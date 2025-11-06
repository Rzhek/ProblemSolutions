#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> adj(n);

    queue<array<int, 3>> q; // {u, src, w}
    vector<int> dist1(n, 1e9), dist2(n, 1e9), source(n, -1);

    while (k--) {
        int u; cin >> u;
        u--;
        dist1[u] = 1e9-1;
        source[u] = u;
        q.push({u, u, 0});
    }

    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    while (q.size()) {
        auto [u, src, w] = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist1[v] == 1e9) {
                dist1[v] = w + 1;
                source[v] = src; 
                q.push({v, src, w + 1});
            } else if (dist2[v] == 1e9 && source[v] != src) {
                dist2[v] = w + 1;
                q.push({v, src, w + 1});
            }
        }
    }

    for (int u = 0; u < n; u++) {
        int w = min(dist1[u], dist2[u]);
        if (w >= 1e9-1) w = -1;
        cout << w << " ";
    }
    cout << "\n";
}
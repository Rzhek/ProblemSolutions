#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int best = 1e9;
    for (int st = 0; st < n; st++) {
        vector<int> dist(n, 1e9);
        dist[st] = 0; 
        queue<array<int, 3>> q{{{st, 0, -1}}};
        while (q.size()) {
            auto [u, w, p] = q.front(); q.pop();
            for (int v : adj[u]) {
                if (v == p) continue;
                if (dist[v] == 1e9) {
                    dist[v] = w + 1;
                    q.push({v, w + 1, u});
                } else {
                    best = min(best, dist[v] + w + 1);
                }
            }
        }
    }
    cout << ((best == 1e9) ? -1 : best) << "\n";
}
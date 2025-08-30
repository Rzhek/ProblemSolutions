#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vi dist(n, 1e6), firstToVisit(n, -1);
    vector<vi> adj(n);
    queue<tuple<int, int, int>> q;
    while (k--) {
        int u; cin >> u; u--;
        q.push({u, u, 0}); // source, cur, dist
    }

    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (q.size()) {
        auto [src, u, w] = q.front();
        // cout << src << " " << u << " " << w << "\n";
        q.pop();
        
        if (u == src && w != 0) continue;
        if (u != src) {

            if (firstToVisit[u] != -1) {
                dist[src] = min(dist[src], w + dist[u]);
                // dist[firstToVisit[u]] = min(dist[firstToVisit[u]], w + dist[u]);
                continue;
            }
            firstToVisit[u] = src;
            dist[u] = w;
        }

        for (int v : adj[u]) {
            q.push({src, v, w + 1});
        }
    }

    for (int u = 0; u < n; u++) {
        cout << (dist[u] < 1e4 ? dist[u] : -1) << " "; 
    }
    cout << "\n";
}
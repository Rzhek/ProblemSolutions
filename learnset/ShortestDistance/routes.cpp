#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, q; cin >> n >> m >> q;
        vector<vector<pii>> edges(n);
        while (m--) {
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }

        vector<int> dist(n, 1e9);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        while (pq.size()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (dist[u] <= w) continue;
            dist[u] = w;
            for (auto [v, dw] : edges[u]) {
                if (dist[v] <= w + dw) continue;
                pq.push({w + dw, v});
            }
        }

        while (q--) {
            int a; cin >> a;
            cout << dist[a-1] << "\n";
        }
    }

    return 0;
}
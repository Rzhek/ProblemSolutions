#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
const int inf = 1e18;

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pll>> edges(n);
    for (int i = 0; i < n; i++) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u].emplace_back(v, w);
    }

    vector<ll> dist(n, inf), changed(n, 0);
    dist[0] = 0;
    for (int i = 0; i <= n; i++) {

        for (int u = 0; u < n; u++) {
            if (dist[u] == inf) continue;
            for (int [v, w] : edges[u]) {
                if (dist[u] + w < dist[v]) {
                    // update
                    dist[v] = dist[u] + w;
                }
            }
        }


    }

    return 0;
}
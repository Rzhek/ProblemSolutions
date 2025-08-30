#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using iii = tuple<ll, ll, ll>;

const ll inf = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pll>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u].emplace_back(v, w);
    }

    vector<vector<ll>> dist(n, vector<ll>(2, inf));
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.emplace(0, 0, 0);
    while (pq.size()) {
        auto [w, used, u] = pq.top();
        pq.pop();
        if (dist[u][used] < w) continue;
        dist[u][used] = w;
        for (auto [v, dw] : edges[u]) {
            if (!used) {
                ll withDistount = w + dw / 2, noDisctount = w + dw;
                if (noDisctount < dist[v][0]) {
                    dist[v][0] = noDisctount;
                    pq.emplace(noDisctount, 0, v);
                }
                if (withDistount < dist[v][1]) {
                    dist[v][1] = withDistount;
                    pq.emplace(withDistount, 1, v);
                }
            } else {
                if (w + dw < dist[v][1]) {
                    dist[v][1] = w + dw;
                    pq.emplace(w + dw, 1, v);
                }
            }
        }
    }

    cout << min(dist[n-1][0], dist[n-1][1]) << '\n';
    return 0;
}
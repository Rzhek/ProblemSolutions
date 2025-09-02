#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vvl mini(n, vl(n, 1e18)), maxi(n, vl(n, -1e18));
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            ll w; cin >> w;
            mini[u][v] = min(mini[u][v], w);
            maxi[u][v] = max(maxi[u][v], w);
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vl dist(n, 1e18);
        pq.push({0, 0});
        while (pq.size()) {
            auto [u, w] = pq.top();
            pq.pop();
            if (dist[u] < w) continue;
            dist[u] = w;
            if (u == n - 1) break;
            for (int v = 0; v < n; v++) {
                ll dw = mini[u][v];
                if (dw == 1e18) continue;
                if (dist[v] < w + dw) continue;
                dist[v] = w + dw;
                pq.emplace(v, w + dw);
            }
        }
        cout << dist[n-1] << " ";


        priority_queue<pll, vector<pll>, greater<pll>> pq1;
        dist = vl(n, -1e18);
        pq1.emplace(0, 0);
        while (pq1.size()) {
            auto [u, w] = pq1.top();
            pq1.pop();
            if (dist[u] > w) continue;
            dist[u] = w;
            if (u == n - 1) continue;
            for (int v = 0; v < n; v++) {
                ll dw = maxi[u][v];
                if (dw == -1e18) continue;
                if (dist[v] > w + dw) continue;
                dist[v] = w + dw;
                pq1.emplace(v, w + dw);
            }
        }
        cout << dist[n-1] << "\n";
    }
    return 0;
}
#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const string danny = "I can't believe Danny won!";
const string sawyer = "Sawyer's style is undeniable!";

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m, d, s; cin >> n >> m >> d >> s;
        d--; s--;
        vector<vector<pll>> edges(n);
        while (m--) {
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }

        vector<ll> dist(n, 1e18);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});
        while (pq.size()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (dist[u] < w) continue;
            dist[u] = w;
            for (auto [v, dw] : edges[u]) {
                if (dist[v] < w + dw) continue;
                dist[v] = w + dw;
                pq.push({w + dw, v});
            }
        }

        if (dist[d] * 2 < dist[s]) cout << danny << "\n";
        else cout << sawyer << "\n";

    }


    return 0;
}
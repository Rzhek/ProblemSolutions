#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<map<int, int>> edges(n);
    vector<int> par(n, -1), visited(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        if (edges[u].find(v) == edges[u].end()) {
            edges[u][v] = w;
            edges[v][u] = w;
        } else {
            edges[u][v] = min(edges[u][v], w);
            edges[v][u] = min(edges[v][u], w);
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    pq.emplace(0, 0);
    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto [v, dw] : edges[u]) {
            if (visited[v]) continue;
            if (w + dw < dist[v]) {
                par[v] = u;
                dist[v] = w + dw;
                pq.emplace(w + dw, v);
            }
        }
    }

    if (dist[n-1] == 1e18) {
        cout << -1 << '\n';
        return 0;
    } 

    vector<int> res;
    int cur = n - 1;
    while (cur != -1) {
        res.push_back(cur);
        cur = par[cur];
    }
    reverse(res.begin(), res.end());
    for (int x : res) cout << x + 1 << " ";
    cout << '\n';

    return 0;
}
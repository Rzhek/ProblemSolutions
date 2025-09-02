#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pii>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }
    vi visited(n, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    ll res = 0;
    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        res += w;
        for (auto [v, dw] : edges[u]) {
            if (visited[v]) continue;
            pq.push({dw, v});
        }
    }
    if (accumulate(visited.begin(), visited.end(), 0) == n) {
        cout << res << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
constexpr ll inf = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pll>> edges(n);
    vector<vector<int>> reversed(n);
    for (int i = 0; i < m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        u--; v--;
        edges[u].emplace_back(v, -w);
        reversed[v].push_back(u);
    }

    vector<ll> dist(n, inf);
    vector<int> changed(n, 0);
    dist[0] = 0;
    for (int iter = 0; iter < max(n, m) + 1; iter++) {
        int last = dist[n-1];
        for (int u = 0; u < n; u++) {
            if (dist[u] == inf) continue;
            for (auto &[v, w] : edges[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (iter == max(n, m)) changed[v] = 1;
                }
            }
        }
    }

    queue<int> q;
    q.push(n-1);
    vector<int> visited(n, 0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (changed[u]) {
            cout << "-1\n";
            return 0;
        }
        for (int v : reversed[u]) {
            if (visited[v]) continue;
            visited[v] = 1;
            q.push(v);
        }
    }

    cout << -dist[n-1] << '\n';
    return 0;
}
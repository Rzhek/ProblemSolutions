#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int n, m; 
vi dist, path, visited;
vvi adj;

void solve(int u = 0) {
    if (visited[u]) return;
    for (int v : adj[u]) {
        solve(v);
        if (dist[v] != -1 && dist[v] + 1 > dist[u]) {
            path[u] = v;
            dist[u] = dist[v] + 1;
        }
    }
    visited[u] = 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    adj = vvi(n);

    while (m--) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
    }

    path = vi(n, -1);
    dist = vi(n, -1);
    visited = vi(n);
    dist[n-1] = 0;
    solve();

    if (dist[0] > -1) {
        cout << dist[0] + 1 << "\n";
        int cur = 0;
        while (cur != n - 1) {
            cout << cur + 1 << " ";
            cur = path[cur];
        }
        cout << cur + 1 << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
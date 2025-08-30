#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

vector<vector<int>> edges; 
vector<int> visited;

int dfs(int u, int prev, int start) {
    if (u == start && prev != -1) return 1;
    if (visited[u]) return 1;
    visited[u] = 1;
    int res = 1;
    for (int v : edges[u]) {
        if (v != prev && !visited[v]) {
            res &= dfs(v, u, u);
        }
    }
    return res && edges[u].size() == 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    edges.resize(n);
    visited.resize(n, 0);
    forn(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int res = 0;
    forn(i, n) {
        if (visited[i]) continue;
        res += dfs(i, -1, i);
    }

    cout << res << '\n';
    return 0;
}
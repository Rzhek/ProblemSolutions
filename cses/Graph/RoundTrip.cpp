#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> visited, res;
vector<vector<int>> edges;


// ans:
// 0 = cycle not found
// 1 = cycle found
// 2 = cycle finished
int dfs(int u, int prev) {
    if (visited[u]) {
        res.push_back(u);
        return 1;
    }
    visited[u] = 1;
    for (int v : edges[u]) {
        if (v == prev) continue;
        int ans = dfs(v, u);
        if (ans == 1) {
            res.push_back(u);
            if (res[0] == u) return 2;
            return 1;
        }
        if (ans == 2) return 2;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    edges.resize(n);
    visited.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges[--u].push_back(--v);
        edges[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (dfs(i, -1) != 0) {
            cout << res.size() << '\n';
            for (auto x : res) {
                cout << x + 1 << " ";
            }
            cout << '\n';
            return 0;
        }  
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
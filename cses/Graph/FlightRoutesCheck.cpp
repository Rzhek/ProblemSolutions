#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

int n, m, timer;
vi tin, low, visited;
vector<pii> bridges;
vi adj[int(1e5+5)];
 
void dfs(int u = 0, int p = 0) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    for(int v : adj[u]){
        if(v != p){
            if(visited[v]) low[u] = min(low[u], tin[v]);
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u])
                    bridges.push_back({u, v});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    // vector<vi> adj = vector<vi>(n);
    while (m--) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }

    tin = low = visited = vi(n);
    dfs();

    if (bridges.size() == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        cout << bridges[0].second + 1 << " " << bridges[0].first + 1 << "\n";
    }
}
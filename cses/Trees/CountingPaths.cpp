#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5, maxk = 18;
int n, m, lift[maxk][maxn], val[maxn], depth[maxn];
vector<int> adj[maxn];

void dfs(int u, int p = 0) {
    lift[0][u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = 1 + depth[u];
        dfs(v, u);
    }
}

void dfs2(int u, int p = 0) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u);
        val[u] += val[v];
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 0; i < maxk; i++) {
        if ((depth[u] - depth[v]) & (1 << i)) {
            u = lift[i][u];
        }
    }
    if (u == v) return u;
    for (int i = maxk - 1; i >= 0; i--) {
        if (lift[i][u] != lift[i][v]) {
            u = lift[i][u];
            v = lift[i][v];
        }
    }
    assert(lift[0][u] == lift[0][v]);
    return lift[0][u];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int jump = 1; jump < maxk; jump++) {
        for (int i = 1; i <= n; i++) {
            lift[jump][i] = lift[jump - 1][lift[jump - 1][i]];
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        val[u]++;
        val[v]++;
        int w = lca(u, v);
        val[w]--;
        val[lift[0][w]]--;
    }

    dfs2(1);

    for (int i = 1; i <= n; i++) {
        cout << val[i] << " ";
    }
    cout << "\n";


}
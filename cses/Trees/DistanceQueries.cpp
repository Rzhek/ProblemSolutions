#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5, maxk = 18;
int n, q, lift[maxk][maxn], depth[maxn];
vector<int> adj[maxn];

void dfs(int u, int p = -1) {
    if (p != -1) depth[u] = depth[p] + 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        lift[0][v] = u;
        dfs(v, u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    for (int jump = 1; jump < maxk; jump++) {
        for (int u = 0; u < n; u++) {
            lift[jump][u] = lift[jump - 1][lift[jump - 1][u]];
        }
    }

    while (q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        int res = depth[u] + depth[v];

        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < maxk; i++) {
            if (diff & (1 << i)) {
                u = lift[i][u];
            }
        }
        
        if (u != v) {
            for (int i = maxk - 1; i >= 0; --i) {
                if (lift[i][u] != lift[i][v]) u = lift[i][u], v = lift[i][v];
            }
            u = lift[0][u];
            v = lift[0][v];
        }
        cout << res - 2 * depth[u] << "\n";
    }
}
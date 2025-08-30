#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
const int maxn = 2e5+5;
int n, q, cur_tree = 0, dp[maxn], tree_idx[maxn], diam[3];
vi adj[maxn];

void dfs1(int u, int p) {
    dp[u] = 1;
    tree_idx[u] = cur_tree;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u] = max(dp[u], 1 + dp[v]);
    }
}

void dfs2(int u, int p, int cur = 0) {
    dp[u] = max(dp[u], cur);
    int max1 = 0, max2 = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (dp[v] >= max1) {
            max2 = max1;
            max1 = dp[v];
        } else if (dp[v] > max2) {
            max2 = dp[v];
        }
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        if (dp[v] == max1) dfs2(v, u, max(cur + 1, max2 + 2));
        else dfs2(v, u, max(cur + 1, max1 + 2));
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(tree_idx, -1, sizeof(tree_idx));
    cin >> n >> q;
    for (int i = 0; i < n - 3; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 0; u < n; u++) {
        if (tree_idx[u] == -1) {
            dfs1(u, -1);
            dfs2(u, -1);
            cur_tree++;
        }
    }

    for (int u = 0; u < n; u++) {
        diam[tree_idx[u]] = max(diam[tree_idx[u]], dp[u]);
    }

    while (q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        cout << diam[3 - tree_idx[v] - tree_idx[u]] + dp[u] + dp[v] << "\n";
    }
}
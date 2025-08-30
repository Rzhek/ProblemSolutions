#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
const int maxn = 2e5+5;
int n, dp[maxn];
vi adj[maxn];

void dfs1(int u, int p) {
    dp[u] = 1;
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
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0, -1);
    dfs2(0, -1);

    for (int i = 0; i < n; i++) cout << dp[i] - 1 << " "; cout << "\n";
}
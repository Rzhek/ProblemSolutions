#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

const int maxn = 2e5+5;
int n, dp[maxn][2]; // 0-1: exclude-include
vi adj[maxn];

void dfs(int u, int p) {
    int sum = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sum += dp[v][1];
    }
    dp[u][0] = max(dp[u][0], sum);
    for (int v : adj[u]) {
        if (v == p) continue;
        dp[u][1] = max(dp[u][1], sum - dp[v][1] + dp[v][0] + 1);
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

    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << "\n";
}
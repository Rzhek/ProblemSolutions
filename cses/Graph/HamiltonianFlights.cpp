#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt") 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int maxn = 20, MOD = 1e9+7;
int n, m, dp[maxn][1 << maxn], adj[maxn][1 << maxn];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u][v]++;
    }
 
    memset(dp, -1, sizeof(dp));
    dp[n - 1][(1 << n) - 1] = 1;
 
    auto solve = [&](int u, int mask, auto solve) -> int {
        int &res = dp[u][mask];
        if (res != -1) return res;
        if (mask & (1 << (n-1))) return 0;
 
        res = 0;
        for (int v = 0; v < n; v++) {
            if (u == v || !adj[u][v] || (mask & (1 << v))) continue;
            res = (res + adj[u][v] * (ll)solve(v, mask | (1 << v), solve)) % MOD;
        }
        return res;
    };
 
 
    cout << solve(0, 1, solve) << "\n";
 
}
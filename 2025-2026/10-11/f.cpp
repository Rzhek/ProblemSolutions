// #pragma GCC optimize("O3,unroll-loops,inline")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt") 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<vector<ll>> dist(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> dist[i][j];
    }

    ll best = 1e18;

    vector<ll> dp(1 << n, best);
    dp[(1 << n) - 1] = 0;
    for (int mask = (1 << n) - 1; mask >= 0; mask--) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            ll tmp = 1e15;
            for (int j = 0; j < n; j++) if (mask & (1 << j)) tmp = min(tmp, dist[i][j]);
            dp[mask] = min(dp[mask], tmp + dp[mask + (1 << i)]);
        }

        if (__builtin_popcount(mask) <= k) best = min(best, dp[mask]);
    }
    cout << best << "\n";
}
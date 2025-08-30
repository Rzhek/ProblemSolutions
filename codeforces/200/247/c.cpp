#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, d; 
const int MOD = 1e9 + 7;
// vector<vector<ll>> memo;

// ll solve(int remain, int used) {
//     if (remain == 0) return used;
//     if (memo[remain][used] >= 0) return memo[remain][used];

//     ll res = 0;
//     for (int i = min(k, remain); i > 0; i--) {
//         res += solve(remain - i, used || (i >= d));
//         res %= MOD;
//     }
//     memo[remain][used] = res;
//     return res;

// }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> d;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) break;
            dp[i][j < d] += dp[i-j][1];
            dp[i][0] += dp[i-j][0];
            dp[i][0] %= MOD;
            dp[i][1] %= MOD;
        }
    }
    cout << dp[n][0] << '\n';
    return 0;
}
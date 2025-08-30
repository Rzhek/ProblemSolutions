#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    vector<vector<ll>> dp(1e6 + 1, vector<ll>(2));
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < dp.size(); ++i) {
        dp[i][0] = 2 * dp[i-1][0] + dp[i-1][1];
        dp[i][1] = 4 * dp[i-1][1] + dp[i-1][0];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    while (t--) {
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }

    return 0;
}

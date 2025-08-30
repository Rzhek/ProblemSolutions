#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    vector<pair<int, ll>> dp(n + 1);
    dp[0] = {1, 0};
    for (int i = 1; i <= n; i++) {
        dp[i] = {(dp[i-1].second * 3) % MOD, (dp[i-1].first + dp[i-1].second * 2) % MOD};
    }
    cout << dp[n].first << '\n';

    // ll T1 = 1, B1 = 0;
    // for (int i = 1; i <= n; i++) {
    //     ll T2 = B1 * 3 % MOD, B2 = T1 + B1 * 2 % MOD;
    //     T1 = T2;
    //     B1 = B2;
    // }
    // cout << T1 << "\n";

    return 0;
}
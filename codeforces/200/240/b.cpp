#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;cin >> n >> k;
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i <= n; i++) dp[k][i] = 1;
    
    for (int i = k - 1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            for (int q = j; q <= n; q += j) {
                dp[i][j] += dp[i+1][q];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[0][1] << '\n';

    return 0;
}
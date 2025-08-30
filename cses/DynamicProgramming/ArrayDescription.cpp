#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

void add(int i, int j, vector<vector<ll>> &dp) {
    dp[i][j] = dp[i-1][j];
    if (j > 0) {
        dp[i][j] += dp[i-1][j-1];
        dp[i][j] %= MOD;
    }
    if (j < dp[i-1].size() - 1) {
        dp[i][j] += dp[i-1][j+1];
        dp[i][j] %= MOD;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    if (nums[0] == 0) {
        for (int i = 0; i < m; ++i) dp[0][i] = 1;
    } else {
        dp[0][nums[0]-1] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (nums[i]) {
            add(i, nums[i]-1, dp);
        } else {
            for (int j = 0; j < m; j++) {
                add(i, j, dp);
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < m; i++) {
        res += dp[n-1][i];
        res %= MOD;
    }

    cout << res << '\n';


    return 0;
}

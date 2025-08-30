#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> dp[i][i];
        sum += dp[i][i];
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = max(dp[i][i] - dp[i+1][j], dp[j][j] - dp[i][j-1]);
        }
    }
    cout << (sum + dp[0][n-1]) / 2 << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    int n = min(N, M), m = max(N, M); 
    vvi dp(n, vi(m));
    for (int i = 0; i < n; ++i) dp[i][0] = i;
    for (int i = 0; i < m; ++i) dp[0][i] = i;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; j++) {
            if (i == j) dp[i][j] = 0;
            else if (i > j) dp[i][j] = dp[j][i];
            else {
                int res = 1e9;
                for (int k = 1; k <= j; k++) {
                    res = min(res, dp[i][j-k] + dp[i][k-1]);
                }
                for (int k = 1; k <= i; k++) {
                    res = min(res, dp[i-k][j] + dp[k-1][j]);
                }
                dp[i][j] = 1 + res;
            }
        }
    }

    // for (auto x : dp) {
    //     for (auto y : x) cout << y << " ";
    //     cout << '\n';
    // }
    cout << dp[n-1][m-1] << '\n';
    return 0;
}
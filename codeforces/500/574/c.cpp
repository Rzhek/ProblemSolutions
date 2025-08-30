#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(2));
    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cin >> dp[j][i];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + dp[i][0]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + dp[i][1]);
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';

    return 0;
}
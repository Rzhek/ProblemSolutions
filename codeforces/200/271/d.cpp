#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int upperBound = 1e5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> nums(n + 1);
    vector<ll> dp(upperBound + 1), sums(upperBound + 1); 
    dp[0] = 1;

    for (int i = 1; i <= upperBound; i++) {
        dp[i] = dp[i-1];
        if (i - k >= 0) dp[i] += dp[i-k];
        dp[i] %= MOD;
    }

    sums[0] = 0;
    for (int i = 1; i <= upperBound; i++) {
        sums[i] = sums[i-1] + dp[i];
        sums[i] %= MOD;
    }

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cout << (sums[b] - sums[a-1] + MOD) % MOD << '\n';
    }



    return 0;
}
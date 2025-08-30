#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

#define rep(i, a, b) for (int i = a; i < b; ++i)

const ll MOD = 1e9 + 7;

ll modInverse(int m) {
    ll* inv = new ll[m + 1] - 1;
    inv[1] = 1;
    rep(i, 2, m + 1) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    return inv[m];
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0 << '\n';
        return 0;
    }
    vvl dp(n + 1, vl(sum / 2 + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum / 2; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0) {
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << (dp[n][sum/2] * modInverse(2)) % MOD << '\n';
    return 0;
}
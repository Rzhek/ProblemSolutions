#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;

int main() {
    vll dp(101, vl(101, 0));
    dp[2][0] = dp[2][1] = 1;
    ll mod = 1001113;
    for (int r = 3; r <= 100; r++)
        for (int c = 0; c <= r; c++)
            dp[r][c] = (c ? (dp[r-1][c] * (c + 1) % mod + dp[r-1][c-1] * (r - c) % mod) % mod : 1);

    int t; cin >> t;
    while (t--) {
        int c, n, k; cin >> c >> n >> k;
        cout << c << " " << dp[n][k] << '\n';
    }
    return 0;
}
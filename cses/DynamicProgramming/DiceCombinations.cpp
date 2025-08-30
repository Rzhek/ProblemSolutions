#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        ll res = 0;
        for (int j = i - 1; j >= max(0, i - 6); --j) {
            res = (res + dp[j]) % mod; 
        }
        dp[i] = res;
    }

    cout << dp[n] << '\n';
    
    return 0;
}
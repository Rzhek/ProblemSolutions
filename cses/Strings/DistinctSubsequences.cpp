#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    vector<ll> dp(26);
    ll res = 0;

    for (int i = 0; i < n; i++) {
        ll val = (res - dp[s[i]-'a'] + 1 + MOD) % MOD;
        dp[s[i]-'a'] += val;
        dp[s[i]-'a'] %= MOD;
        res += val;
        res %= MOD;
    }

    cout << res << "\n";
}
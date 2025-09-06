#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7, MODINV = 5e8+4;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    ll res = 0;
    ll cur = 1;
    while (cur <= n) {
        ll amt = n / cur;
        ll last = n / amt;
        
        res += amt % MOD * ((last % MOD) * ((last + 1) % MOD) % MOD * MODINV % MOD) % MOD;
        res -= amt % MOD * ((cur % MOD) * ((cur - 1) % MOD) % MOD * MODINV % MOD) % MOD;
        res = (res + MOD) % MOD;
        
        cur = last + 1;
    }

    cout << res << "\n";

}
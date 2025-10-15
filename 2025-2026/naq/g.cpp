#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

ll fastpow(ll x, ll e) {
    if (e == 0) return 1;
    ll res = fastpow(x, e / 2);
    res = res * res % MOD;;
    if (e % 2) return (x * res) % MOD;
    return res;
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    cout << (fastpow(2ll * k * fastpow(2 * k + 1, MOD - 2) % MOD, 2 * k) * n) % MOD << "\n";
}

// 3 1
// 4 / 3
// 4 / 9 * 3
// 2 / 3 * 2 / 3 * 3
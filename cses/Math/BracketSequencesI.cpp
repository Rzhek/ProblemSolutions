#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7, maxn = 1e6+6;
ll fact[maxn];

ll fastexp(ll a, ll e) {
    if (e == 0) return 1;
    if (e % 2) return (a * fastexp(a, e-1)) % MOD;
    ll res = fastexp(a, e / 2);
    res = (res * res) % MOD;
    return res;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) fact[i] = (fact[i-1] * i) % MOD;

    int n; cin >> n;
    if (n % 2) cout << "0\n";
    else {
        cout << ((fact[n] * fastexp(fact[n/2], MOD - 2)) % MOD * fastexp(fact[n/2+1], MOD - 2)) % MOD << "\n";
    }
}

// 2n! / (n)! / (n+1)!
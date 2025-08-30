#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7, maxn = 2e6+1;
ll fact[maxn];

ll fastpow(ll a, int e) {
    if (e == 0) return 1;
    ll res = fastpow(a, e / 2);
    res = res * res % MOD;
    if (e % 2) res = res * a % MOD;
    return res;
}

ll choose(int n, int k) {
    return fact[n] * fastpow(fact[k], MOD - 2) % MOD * fastpow(fact[n-k], MOD - 2) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) fact[i] = fact[i-1] * i % MOD;

    int children, apples; cin >> children >> apples;

    cout << choose(children + apples - 1, children - 1) << "\n";
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7, maxn = 1e6+1;
ll fact[maxn];

ll fastpow(ll a, int e) {
    if (e == 0) return 1;
    ll res = fastpow(a, e / 2);
    res = res * res % MOD;
    if (e % 2) res = res * a % MOD;
    return res;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) fact[i] = fact[i-1] * i % MOD;
    while (n--) {
        int a, b; cin >> a >> b;
        cout << fact[a] * fastpow(fact[b], MOD - 2) % MOD * fastpow(fact[a - b], MOD - 2) % MOD << "\n";
    }

}
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

ll choose(int n, int k) {
    if (n < k) return 0;
    return (fact[n] * fastexp((fact[k] * fact[n-k]) % MOD, MOD - 2)) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) fact[i] = (fact[i-1] * i) % MOD;

    int n; cin >> n;
    if (n % 2) return cout << "0\n", 0;
    string s; cin >> s;
    int k = s.size();
    int open = 0, close = 0;
    for (char ch : s) {
        open += ch == '(';
        close += ch == ')';
        if (close > open) return cout << "0\n", 0;
    }
    if (open * 2 > n) return cout << "0\n", 0;

    n -= k;
    int rem = (n + open - close) / 2;
    cout << (choose(n, rem) - choose(n, rem + 1) + MOD) % MOD << "\n";

}
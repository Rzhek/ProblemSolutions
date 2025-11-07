#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

ll fastExp(ll a, ll e) {
    if (e == 0) return 1;
    if (e % 2) return (a * fastExp(a,e-1)) % MOD;
    ll res = fastExp(a, e / 2);
    return (res * res) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    ll totCnt = 0;
    ll totSum = 0;
    ll totProd = 1;
    
    ll exp = 0;

    for (int i = 0; i < n; i++) {
        ll tmp1 = fastExp(totProd, b[i] + 1);
        ll tmp2 = fastExp(a[i], exp);
        ll tmp3 = ((b[i] * (b[i] + 1)) / 2);
        ll tmp4 = (tmp1 * fastExp(tmp2, tmp3)) % MOD;
        totProd = (tmp4 * fastExp(a[i], tmp3)) % MOD;

        totCnt += ((totCnt + 1) * b[i]) % MOD;
        totCnt %= MOD;
        exp += ((exp + 1) * b[i]) % (MOD - 1);
        exp %= (MOD - 1);
    }
    totCnt += 1;

    for (int i = 0; i < n; i++) {
        ll tmp = ((fastExp(a[i], b[i] + 1) - 1) * fastExp(a[i] - 1, MOD - 2) - 1) % MOD;
        totSum += ((totSum+1) * tmp) % MOD;
        totSum %= MOD;
    }
    totSum += 1;


    cout << totCnt << " " << totSum << " " << totProd << "\n";
}
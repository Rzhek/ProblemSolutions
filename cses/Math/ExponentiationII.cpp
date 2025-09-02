#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;


ll fastPow(ll num, int e, const int MOD) {
    if (e == 0) return 1;
    if (e == 1) return num;
    ll res = fastPow(num, e / 2, MOD);
    res = res * res % MOD;
    if (e & 1) res = res * num % MOD;
    return res;  
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        cout << fastPow(a, fastPow(b, c, 1e9+6), 1e9+7) << "\n";
    }
 
    return 0;
}
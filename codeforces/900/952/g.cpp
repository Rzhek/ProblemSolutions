#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using iii = tuple<int, int, int>;

const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

ll fastExpo(ll x, ll e) {
    if (e == 0) return 1;
    if (e == 1) return x;
    ll res = fastExpo(x, e / 2);
    res *= res;
    res %= MOD;
    if (e & 1) {
        res *= x;
        res %= MOD;
    }
    return res;
}

ll modInverse(int m) {
    ll* inv = new ll[m + 1] - 1;
    inv[1] = 1;
    rep(i, 2, m + 1) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    return inv[m];
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int l, r, k; cin >> l >> r >> k;
        if (k >= 10) {
            cout << 0 << "\n";
            continue;
        }
        ll res = 0;
        int digits = 9 / k;
        ll x = digits + 1;
        res =((fastExpo(x, r) - fastExpo(x, l) + MOD) * modInverse(x - 1)) % MOD;
        res *= x - 1;
        res %= MOD;
        cout << (res + MOD) % MOD << "\n";
    }
    return 0;
}
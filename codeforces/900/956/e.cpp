#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
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

ll fastExpo(int a, int e) {
    if (e == 0) return 1ll;
    if (e == 1) return a;
    ll res = fastExpo(a, e / 2);
    res = res * res % MOD;
    if (e & 1) res = res * a % MOD;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, k; cin >> n >> k;
        vl v(n);
        forn (i, n) cin >> v[i];

        int ns = n - k;
        int a = (ns + 1) / 2, b = ns / 2;
        int c = (ns+1 + 1) / 2, d = (ns+1) / 2;

        ll special = accumulate(v.begin(), v.begin() + k, 0ll) % MOD;
        ll nonSpecial = accumulate(v.begin() + k, v.end(), 0ll) % MOD;

        ll res1 = special * c % MOD * fastExpo(ns+1, MOD-2) % MOD;
        res1 += nonSpecial * a % MOD * fastExpo(ns, MOD-2) % MOD;
        res1 %= MOD;

        ll res2 = special * d % MOD * fastExpo(ns+1, MOD-2) % MOD;
        res2 += nonSpecial * b % MOD * fastExpo(ns, MOD-2) % MOD;
        res2 %= MOD;

        cout << res1 << " " << res2 << "\n";
    }
    return 0;
}
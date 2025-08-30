#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
#define forn(i, n) for (int i = 0; i < n; ++i)
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const int mod2inv = 500000004;
const long double EPS = 1e-9;


const int maxn = 2e5+1;
struct BIT {
    ll vals[maxn];
    void add(int p, int val) { // make sure to convert to 1 base index
        // otherwise uncomment
        for (/*p++*/; p < maxn; p += p&-p) vals[p] = (vals[p] + val) % MOD;
    }
    ll get(int p) { // inclusive [0, p]
        ll sum = 0;
        for (; p; p -= p&-p) sum = (sum + vals[p]) % MOD;
        return sum;
    }
    ll get(int a, int b) { // [a, b]
        return (get(b) - get(a - 1) + MOD) % MOD;
    }
};

BIT left, right;

ll fastExpo(ll a, int e) {
    if (e == 0) return 1ll;
    if (e == 1) return a;
    ll res = fastExpo(a, e / 2);
    res = res * res % MOD;
    if (e & 1) res = res * a % MOD;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    double _; cin >> _;
    ll num = _ * 1e6;
    ll den = 1e6;

    ll p = (den - num) * fastExpo(den, MOD - 2) % MOD;
    ll p_inv = den * fastExpo(den - num, MOD - 2) % MOD;

    while (m--) {
        char type; cin >> type;
        if (type == '+' || type == '-') {
            int b, x; cin >> b >> x;
            if (type == '-') b = MOD - b;
            ::left.add(x, (b * fastExpo(p_inv, x - 1)) % MOD);
            ::right.add(x, (b * fastExpo(p_inv, n - x)) % MOD);
        } else {
            int x; cin >> x;
            ll res = ::left.get(1, x) * fastExpo(p, x - 1) % MOD;
            res += ::right.get(x + 1, n) * fastExpo(p, n - x) % MOD;
            res %= MOD;
            cout << res << "\n";
        }
    }
}
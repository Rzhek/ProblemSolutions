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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vi a(n), b(n);
    forn (i, n) cin >> a[i];
    forn (i, n) cin >> b[i];
    
    int maxi = *max_element(all(a)) + 1;
    vl best(maxi, 1e9), calc(maxi, 0);

    forn (i, n) {
        best[a[i]] = min(best[a[i]], (ll)a[i]-b[i]);
    } 
    rep (v, 1, maxi) {
        best[v] = min(best[v], best[v-1]);
    }
    rep (v, 1, maxi) {
        if (v >= best[v]) calc[v] = 2 + calc[v - best[v]];
    }

    ll res = 0;
    forn (i, m) {
        int c; cin >> c;
        if (c >= maxi) {
            ll k = (c - maxi + 1 + best[maxi-1]) / best[maxi-1];
            res += 2 * k;
            c -= k * best[maxi-1];
        }
        res += calc[c];
    }
    cout << res << "\n";
    return 0;
}
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<iii> pulses(n*2);
    forn (i, n) {
        char d; cin >> d;
        int t, m, a; cin >> t >> m >> a;
        pulses[i] = {t-a, 1, d};
        pulses[n+i] = {t-a+m, -1,d};
    }
    sort(all(pulses), [](const auto &a, const auto &b) {
        auto [t1, delta1, type1] = a;
        auto [t2, delta2, type2] = b;
        if (t1 != t2) return t1 < t2;
        if (delta1 != delta2) return delta1 < delta2;
        return type1 < type2;
    });

    ll res = 0;
    int hCount = 0, vCount = 0;
    for (const auto [t, delta, type] : pulses) {
        if (type == 'h') {
            hCount += delta;
            if (delta == 1) res += vCount;
        } else {
            vCount += delta;
            if (delta == 1) res += hCount;
        }
    }
    cout << res << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
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
    int s, t, n; cin >> s >> t >> n;
    vpi blades(n);
    forn(i, n) {
        cin >> blades[i].f >> blades[i].s;
    }
    sort(all(blades), [](pii a, pii b) {
        return a.s < b.s;
    });

    // for (auto [x, y] : blades) {
    //     cout << x << " " << y << "\n";
    // }

    int cur = t;
    long double res = 0;
    
    for (int i = 0; i < n; i++) {
        if (cur >= blades[i].f) continue;
        int nextSize = min(s, blades[i].f);
        res += blades[i].s * (log2(nextSize) - log2(cur));
        cur = nextSize;
    }

    // cout << res << "\n";
    if (cur != s) {
        cout << "-1\n";
    } else {
        cout << fixed << setprecision(20) << res << "\n";
    }
    

    return 0;
}
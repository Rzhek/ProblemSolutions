#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
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
    int n, x; cin >> n >> x;
    vi a(n);
    vpi dp(1 << n);
    forn (i, n) cin >> a[i];

    dp[0] = {1, 0};
    for (int state = 1; state < (1 << n); state++) {
        dp[state] = {n + 1, 0};
        for (int i = 0; i < n; i++) {
            if (!(state & (1 << i))) continue;
            auto opt = dp[state ^ (1 << i)];
            if (opt.s + a[i] <= x) {
                opt.s += a[i];
            } else {
                opt.f++;
                opt.s = a[i];
            }
            dp[state] = min(dp[state], opt);
        }
    }

    cout << dp[(1 << n) - 1].f << "\n";

    return 0;
}
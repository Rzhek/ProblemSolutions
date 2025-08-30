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
    int ox, ni; cin >> ox >> ni;
    int n; cin >> n;
    vvi dp(25, vi(85, 1e9));
    dp[0][0] = 0;
    // this code sucks but if it works it works
    // idea: set bounds to ox, ni
    // top-down dp: if not 1e9, set dp[min(r+a, ox)][min(c+b, ni)] to dp[r][c] + w (if less)
    forn (i, n) {
        int a, b, w; cin >> a >> b >> w;
        for (int r = 24; r >= a; r--) {
            for (int c = 79; c >= b; c--) {
                if (dp[r-a][c-b] == 1e9) continue;
                for (int r1 = r - a; r1 <= r; r1++) {
                    for (int c1 = c - b; c1 <= c; c1++) {
                        dp[r1][c1] = min(dp[r1][c1], dp[r-a][c-b] + w);
                    }
                }
            }
        }
    }

    cout << dp[ox][ni] << "\n";


    return 0;
}
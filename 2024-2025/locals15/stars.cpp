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
    int cases; cin >> cases;
    for (int t = 1; t <= cases; t++) {
        int n, m; cin >> n >> m;
        vvi isMarked(n, vi(m)), canMark(n, vi(m));
        forn (r, n) {
            forn (c, m) {
                char ch; cin >> ch;
                isMarked[r][c] = ch == '#';
            }
        }

        for (int r = 1; r < n - 1; r++) {
            for (int c = 1; c < m - 1; c++) {
                canMark[r-1][c] = isMarked[r-1][c] && isMarked[r][c-1] && isMarked[r+1][c] && isMarked[r][c+1] && isMarked[r][c];
            }
        }

        int stampMask = 1 | (1 << (m-1)) | (1 << m) | (1 << (m+1)) | (1 << (2 * m));
        vvi dp(n * m + 1, vi(1 << (2 * m), 1e9));
        dp[0][0] = 0;
        forn (r, n) {
            forn (c, m) {
                int cur = r * m + c;
                for (int mask = 0; mask < (1 << (2 * m)); mask++) {
                    if (dp[cur][mask] >= 1e9) continue;
                    if (canMark[r][c]) {
                        int nxtMask = (mask | stampMask) >> 1;
                        dp[cur+1][nxtMask] = min(dp[cur+1][nxtMask], dp[cur][mask]+1);
                    }
                    if (!isMarked[r][c] || (mask & 1)) {
                        int nxtMask = mask >> 1;
                        dp[cur+1][nxtMask] = min(dp[cur+1][nxtMask], dp[cur][mask]);
                    }
                }
            }
        }

        cout << "Image #" << t << ": ";
        if (dp[n * m][0] == 1e9) cout << "impossible\n\n";
        else cout << dp[n*m][0] << "\n\n";
    }
    return 0;
}
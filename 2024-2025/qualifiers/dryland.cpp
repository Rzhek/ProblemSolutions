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
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1)), sums(n + 1, vector<int>(m + 1));
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            char ch; cin >> ch;
            grid[r][c] = ch == '1';
            sums[r][c] = ch == '1';
        }
    }

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            sums[r][c] += sums[r][c-1];
        }
    }
    for (int c = 1; c <= m; c++) {
        for (int r = 1; r <= n; r++) {
            sums[r][c] += sums[r-1][c];
        }
    }

    int best = 0;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            for (int r1 = 1; r1 <= r; r1++) {
                for (int c1 = 1; c1 <= c; c1++) {
                    int dr = r - r1 + 1;
                    int dc = c - c1 + 1;
                    if (sums[r][c] - sums[r1-1][c] - sums[r][c1-1] + sums[r1-1][c1-1] == dr * dc) {
                        best = max(best, dr * dc);
                    }
                }
            }
        }
    }

    cout << best << "\n";

    // print2DArr(sums);
    

    return 0;
}
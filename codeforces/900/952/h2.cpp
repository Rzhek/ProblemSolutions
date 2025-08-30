#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).compSize()
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

int n, m;
int minR, maxR, minC, maxC, compSize;
vector<vector<char>> grid;
vi rows, cols, dotsR, dotsC;
vvi visited, over;

void dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] == '.') return;

    visited[r][c] = 1;
    compSize++;
    minR = min(minR, r);
    maxR = max(maxR, r);
    minC = min(minC, c);
    maxC = max(maxC, c);

    dfs(r-1, c);
    dfs(r+1, c);
    dfs(r, c-1);
    dfs(r, c+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        cin >> n >> m;
        grid.assign(n, vector<char>(m));
        rows.assign(n+2, 0);
        cols.assign(m+2, 0);
        dotsR.assign(n, 0);
        dotsC.assign(m, 0);
        visited.assign(n, vi(m, 0));
        over.assign(n+2, vi(m+2, 0));

        forn (r, n) forn (c, m) {
            cin >> grid[r][c];

            if (grid[r][c] == '.') {
                dotsR[r]++;
                dotsC[c]++;
            }
        }

        forn (r, n) forn (c, m) {
            if (visited[r][c] || grid[r][c] == '.') continue;

            compSize = 0;
            minR = n; maxR = 0;
            minC = m; maxC = 0;

            dfs(r, c);

            minR = max(minR-1, 0);
            maxR = min(maxR+1, n-1);
            minC = max(minC-1, 0);
            maxC = min(maxC+1, m-1);

            rows[minR+1] += compSize;
            rows[maxR+2] -= compSize;
            cols[minC+1] += compSize;
            cols[maxC+2] -= compSize;

            over[minR+1][minC+1] += compSize;
            over[maxR+2][minC+1] -= compSize;
            over[minR+1][maxC+2] -= compSize;
            over[maxR+2][maxC+2] += compSize;
        }

        rep (r, 1, n + 1) rows[r] += rows[r-1];
        rep (c, 1, m + 1) cols[c] += cols[c-1];
        rep (r, 1, n + 1) rep (c, 1, m + 1) {
            over[r][c] += over[r-1][c] + over[r][c-1] - over[r-1][c-1];
        }

        int res = 0;
        rep (r, 1, n + 1) rep (c, 1, m + 1) {
            res = max(res, rows[r] + cols[c] - over[r][c] + dotsR[r-1] + dotsC[c-1] - (grid[r-1][c-1] == '.'));
        }

        cout << res << "\n";
    }


    return 0;
}
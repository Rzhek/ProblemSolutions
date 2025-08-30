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

vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

void dfs(vvi &canEscape, vector<string> &grid, int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m || canEscape[r][c] || grid[r][c] == '#') return;
    canEscape[r][c] = 1;
    for (auto [dr, dc] : dirs) {
        dfs(canEscape, grid, r+dr, c+dc);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        cin >> n >> m;
        vector<string> grid(n);
        vpi bad, good;
        forn (r, n) {
            cin >> grid[r];
            forn (c, m) {
                if (grid[r][c] == 'G') good.emplace_back(r, c);
                if (grid[r][c] == 'B') bad.emplace_back(r, c);
            }
        }

        for (auto [R, C] : bad) {
            for (auto [dr, dc] : dirs) {
                int r = R + dr, c = C + dc;
                if (0 <= r && r < n && 0 <= c && c < m && grid[r][c] == '.') {
                    grid[r][c] = '#';
                }
            }
        }

        vvi canEscape(n, vi(m, 0));
        dfs(canEscape, grid, n-1, m-1);

        int works = 1;
        for (auto [r, c] : good) {
            works &= canEscape[r][c];
        }
        for (auto [r, c] : bad) {
            works &= !canEscape[r][c];
        }


        cout << (works ? "Yes" : "No") << "\n";
    }
    return 0;
}
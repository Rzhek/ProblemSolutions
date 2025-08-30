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

int bfs(vector<string> grid, int n) {
    int res = 0;
    forn (i, 2) {
        forn (j, n) {
            if (grid[i][j] == '.') {
                res++;
                queue<pii> q;
                q.emplace(i, j);
                grid[i][j] = 'x';
                while (q.size()) {
                    auto [r, c] = q.front();
                    q.pop();
                    for (auto [dr, dc] : dirs) {
                        int nr = r + dr, nc = c + dc;
                        if (nr < 0 || nr >= 2 || nc < 0 || nc >= n || grid[nr][nc] == 'x') continue;
                        q.emplace(nr, nc);
                        grid[nr][nc] = 'x';
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vector<string> grid(2);
        cin >> grid[0] >> grid[1];
        int regions = bfs(grid, n);


        int res = 0;
        forn (r, 2) {
            forn (c, n) {
                if (grid[r][c] == 'x') continue;
                if (c - 1 < 0 || c + 1 >= n) continue;
                if (grid[r][c-1] == 'x' || grid[r][c+1] == 'x') continue;

                if (grid[1-r][c] == '.') {
                    if (grid[1-r][c-1] == 'x' && grid[1-r][c+1] == 'x') res += regions + 2 == 3;
                    continue;
                }

                // cout << r << " " << c << "\n";
                if (grid[1-r][c-1] == 'x' || grid[1-r][c] == 'x' || grid[1-r][c+1] == 'x') res += regions + 1 == 3;
            }
        }

        cout << res << "\n";
    }
    return 0;
}
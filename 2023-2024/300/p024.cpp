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

int rows, cols, k; 
int winner, winMove;
// {player, time}
vector<vpi> grid;

int check(int move) {
    // check horizontal
    for (int r = 0; r < rows; r++) {
        int maxMove = -1;
        int player = 0;
        int cur = 0;
        for (int c = 0; c < cols; c++) {
            if (grid[r][c].s > move) {
                cur = 0;
                maxMove = -1;
                continue;
            }
            if (grid[r][c].f == player) {
                cur++;
                maxMove = max(maxMove, grid[r][c].s);
            } else {
                cur = 1;
                maxMove = grid[r][c].s;
                player ^= 1;
            }
            if (cur == k) {
                winner = player;
                winMove = maxMove;
                return 1;
            }
        }
    }

    // check vertical
    for (int c = 0; c < cols; c++) {
        int maxMove = -1;
        int player = 0;
        int cur = 0;
        for (int r = 0; r < rows; r++) {
            if (grid[r][c].s > move) {
                cur = 0;
                maxMove = -1;
                continue;
            }
            if (grid[r][c].f == player) {
                cur++;
                maxMove = max(maxMove, grid[r][c].s);
            } else {
                cur = 1;
                maxMove = grid[r][c].s;
                player ^= 1;
            }
            if (cur == k) {
                winner = player;
                winMove = maxMove;
                return 1;
            }
        }
    }

    // check diagonal 1 \ 
    //
    vpi start;
    forn (i, rows-1) start.emplace_back(i, 0);
    forn (i, cols) start.emplace_back(rows-1, i);
    for (auto [r, c] : start) {
        int maxMove = -1;
        int player = 0;
        int cur = 0;
        for (; r >= 0 && c < cols; r--, c++) {
            // cout << r << " " << c << "\n";
            if (grid[r][c].s > move) {
                cur = 0;
                maxMove = -1;
                continue;
            }
            if (grid[r][c].f == player) {
                cur++;
                maxMove = max(maxMove, grid[r][c].s);
            } else {
                cur = 1;
                maxMove = grid[r][c].s;
                player ^= 1;
            }
            if (cur == k) {
                winner = player;
                winMove = maxMove;
                return 1;
            }
        }
        // cout << "\n";
    }
    
    // check diagonal 2 /
    start.clear();
    forn (i, rows-1) start.emplace_back(i, cols-1);
    forn (i, cols) start.emplace_back(rows-1, i);
    for (auto [r, c] : start) {
        int maxMove = -1;
        int player = 0;
        int cur = 0;
        for (; r >= 0 && c >= 0; r--, c--) {
            // cout << r << " " << c << "\n";
            if (grid[r][c].s > move) {
                cur = 0;
                maxMove = -1;
                continue;
            }
            if (grid[r][c].f == player) {
                cur++;
                maxMove = max(maxMove, grid[r][c].s);
            } else {
                cur = 1;
                maxMove = grid[r][c].s;
                player ^= 1;
            }
            if (cur == k) {
                winner = player;
                winMove = maxMove;
                return 1;
            }
        }
        // cout << "\n";
    }


    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> rows >> cols >> k;
    grid.resize(rows, vpi(cols));
    vi maxHeight(cols, 0);
    forn(i, rows * cols) {
        int col; cin >> col;
        col--;
        int row = maxHeight[col]++;
        grid[row][col] = {i & 1, i+1};
    }

    // for (int i = rows-1; i >= 0; i--) {
    //     for (auto y : grid[i]) {
    //         cout << y.f << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    // for (int i = rows-1; i >= 0; i--) {
    //     for (auto y : grid[i]) {
    //         cout << y.s << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    if (!check(rows * cols)) {
        cout << "D\n";
        return 0;
    }
    int lo = 1, hi = rows * cols - 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (check(m)) {
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }

    cout << "AB"[winner] << " " << winMove << "\n";




    
    return 0;
}
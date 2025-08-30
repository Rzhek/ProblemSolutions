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
const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
vector<vector<char>> grid;
int total = 0;

void markRect1(int r1, int c1, char ch, vector<vector<char>> &grid) {
    int r2 = r1;
    while (r2 < n && grid[r2][c1] == '#') r2++;
    for (int c = c1; c < m; c++) {
        for (int r = r1; r < r2; r++) {
            if (grid[r][c] == '.') return;
            if (grid[r][c] == 'a' && total == 0) return;
        }
        for (int r = r1; r < r2; r++) {
            total -= grid[r][c] == '#';
            grid[r][c] = ch;
        }
    }
}

void markRect2(int r1, int c1, char ch, vector<vector<char>> &grid) {
    int c2 = c1;
    while (c2 < m && grid[r1][c2] == '#') c2++;
    for (int r = r1; r < n; r++) {
        for (int c = c1; c < c2; c++) {
            if (grid[r][c] == '.') return;
            if (grid[r][c] == 'a' && total == 0) return;
        }
        for (int c = c1; c < c2; c++) {
            total -= grid[r][c] == '#';
            grid[r][c] = ch;
        }
    }
}

void dfs(int r, int c, char t, vvi &visited, vector<vector<char>> &grid) {
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] != t) return;
    visited[r][c] = 1;
    for (auto [dr, dc] : dirs) {
        dfs(r+dr, c+dc, t, visited, grid);
    }
}
int checkComponents(vector<vector<char>> grid) {
    vvi visited(n, vi(m, 0));
    int res = 0;
    forn (r, n) {
        forn (c, m) {
            if (grid[r][c] == '.' || visited[r][c]) continue;
            res++;
            dfs(r, c, grid[r][c], visited, grid);
        }
    }
    return res == 2;
}

pair<int, vector<vector<char>>> solve(int type, vector<vector<char>> grid) {
    int firstR = -1, firstC = -1;
    total = 0;
    forn (r, n) {
        forn (c, m) {
            total += grid[r][c] == '#';
            if (grid[r][c] == '#' && firstR == -1) firstR = r, firstC = c;
        }
    }
    if (total <= 1) return {0, grid};

    char ch = 'a';
    forn (r, n) {
        forn (c, m) {
            if (grid[r][c] != '#') continue;
            if (ch == 'c') return {0, grid};
            // markRect1(r, c, ch);
            if (type == 1) markRect1(r, c, ch, grid);
            else markRect2(r, c, ch, grid);
            ch++;
        }
    }
    if (total > 0) return {0, grid};
    if (ch == 'b') {
        int distR = 0, distC = 0;
        while (firstR + distR < n && grid[firstR+distR][firstC] == 'a') distR++;
        while (firstC + distC < m && grid[firstR][firstC+distC] == 'a') distC++;
        if (distC > 1) {
            for (int r = firstR; r < firstR + distR; r++) grid[r][firstC] = 'b';
            return {checkComponents(grid), grid};
        }
        if (distR > 1) {
            for (int c = firstC; c < firstC + distC; c++) grid[firstR][c] = 'b';
            return {checkComponents(grid), grid};
        }
        assert(true);

    }
    return {checkComponents(grid), grid};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    grid = vector<vector<char>>(n, vector<char>(m));
    forn (r, n) {
        forn (c, m) cin >> grid[r][c];
    }
    auto [a, b] = solve(1, grid);
    if (a) {
        cout << "YES\n";
        forn (r, n) {
            forn (c, m) cout << b[r][c];
            cout << "\n";
        }
        return 0;
    } 
    auto [c, d] = solve(2, grid);
    if (c) {
        cout << "YES\n";
        forn (r, n) {
            forn (c, m) cout << d[r][c];
            cout << "\n";
        }
        return 0;
    } 
    cout << "NO\n";
    return 0;
}
#pragma GCC optimize("O3")
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

const int n = 7;
const int pathlen = n * n - 1;
int visited[n+2][n+2];
vpi moves[n*n-1];

int bt(int r, int c, int len = 0) {
    if (visited[r][c]) return 0;
    if (r == n && c == 1) return len == pathlen;
    if (len == pathlen) return 0;
    if (visited[r+1][c] && visited[r-1][c] && !visited[r][c-1] && !visited[r][c+1]) return 0;
    if (!visited[r+1][c] && !visited[r-1][c] && visited[r][c-1] && visited[r][c+1]) return 0;


    int res = 0;
    visited[r][c] = 1;
    for (auto [dr, dc] : moves[len]) {
        int nr = r + dr, nc = c + dc;
        res += bt(nr, nc, len + 1);
    }
    visited[r][c] = 0;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    assert(s.size() == pathlen);
    forn (i, pathlen) {
        if (s[i] == '?') moves[i] = dirs;
        if (s[i] == 'U') moves[i].pb(dirs[0]);
        if (s[i] == 'D') moves[i].pb(dirs[1]);
        if (s[i] == 'L') moves[i].pb(dirs[2]);
        if (s[i] == 'R') moves[i].pb(dirs[3]);
    }
    
    forn (r, n + 2) {
        forn (c, n + 2) {
            visited[r][c] = r == 0 || r == n + 1 || c == 0 || c == n + 1;
        }
    } 

    cout << bt(1, 1) << "\n";

    return 0;
}
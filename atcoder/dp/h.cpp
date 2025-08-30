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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vvl dp(n, vl(m, 0)); dp[0][0] = 1;
    forn (r, n) forn (c, m) {
        cin >> grid[r][c];
    }
    
    forn (r, n) forn (c, m) if (grid[r][c] == '.') {
        if (r) dp[r][c] += dp[r-1][c];
        if (c) dp[r][c] += dp[r][c-1];
        dp[r][c] %= MOD;
    }

    // print2DArr(dp);
    cout << dp[n-1][m-1] << "\n";
    return 0;
}
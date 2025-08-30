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

int n, m;
double p;
const int maxn = 1e3+10;
double memo[maxn+1][maxn+1];

// r <= c always
double solve(int r, int c) {
    if (c > r) return solve(c, r);
    if (c == 0) return memo[r][c] = r * p / 4.0;
    if (memo[r][c] >= 0) return memo[r][c];

    double a = solve(r-1, c), b = solve(r, c-1);
    double diff = a-b;
    return memo[r][c] = ((a+b)/2.0 - diff * diff / p / 4.0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> p;
    forn (r, maxn+1) forn (c, maxn+1) memo[r][c] = -1.0;
    cout << fixed << setprecision(10) << solve(n-1, m-1) << "\n";

    return 0;
}
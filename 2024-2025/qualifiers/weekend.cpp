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


int cost[3], num[3];
int l, h;

double solve(int a, int b, int c, vector<vector<vector<double>>> &dp) {
    int cur = a * cost[0] + b * cost[1] + c * cost[2];
    if (cur > h) return 0;
    int options = num[0] + num[1] + num[2] - a - b - c;
    if (l <= cur && cur <= h) return 1;
    if (dp[a][b][c] != -1) return dp[a][b][c];

    double res = 0;
    if (num[0] - a > 0) {
        res += (num[0] - a) * solve(a + 1, b, c, dp);
    }
    if (num[1] - b > 0) {
        res += (num[1] - b) * solve(a, b + 1, c, dp);
    }
    if (num[2] - c > 0) {
        res += (num[2] - c) * solve(a, b, c + 1, dp);
    }
    // if (l <= cur && cur <= h) res += 1;
    res = res / options;
    return dp[a][b][c] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> l >> h;
    forn (i, 3) cin >> cost[i];
    forn (i, 3) cin >> num[i];
    vector<vector<vector<double>>> dp(num[0] + 1, vector<vector<double>>(num[1] + 1, vector<double>(num[2] + 1, -1)));
    double res = solve(0, 0, 0, dp);
    cout << fixed << setprecision(10);
    if (isnan(res)) cout << 0 << '\n';
    else cout << res << "\n";

    return 0;
}
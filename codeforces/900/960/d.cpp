#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
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

const int maxn = 2e5 + 20;
int n, a[maxn], dp[maxn][2][2];

int solve(int ind, int first, int last) {
    if (ind == n) return 0;

    if (dp[ind][first][last] < 1e9) return dp[ind][first][last];

    int res = (a[ind] != 0) + solve(ind + 1, 0, 0);
    if (a[ind] <= 2) {
        if (first) res = min(res, solve(ind + 1, 0, 0));
        else res = min(res, 1 + solve(ind + 1, 1, 0));
    } else if (a[ind] <= 4) {
        if (first && last) res = min(res, solve(ind + 1, 0, 0));
        else if (first) res = min(res, 1 + solve(ind + 1, 0, 1));
        else if (last) res = min(res, 1 + solve(ind + 1, 1, 0));
        else res = min(res, 2 + solve(ind + 1, 1, 1));
    }

    return dp[ind][first][last] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    tests {
        cin >> n;
        forn (i, n) cin >> a[i];
        forn (i, n) forn (j, 2) forn (k, 2) dp[i][j][k] = 1e9;

        cout << solve(0, 0, 0) << "\n";
    }

    return 0;
}
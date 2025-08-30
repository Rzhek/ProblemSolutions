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
    int n; cin >> n;
    vector<double> probs(n);
    forn (i, n) cin >> probs[i];

    vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
    dp[0][0] = 1;
    rep (i, 1, n + 1) {
        dp[i][0] = dp[i-1][0] * (1 - probs[i-1]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j-1] * probs[i-1] + dp[i-1][j] * (1-probs[i-1]);
        }
    }

    // cout << fixed << setprecision(3);
    // print2DArr(dp);

    double res = 0;
    for (int i = n / 2 + 1; i <= n; i++) res += dp[n][i];
    cout << fixed << setprecision(10) << res << "\n";

    
    return 0;
}
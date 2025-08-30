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

// int intersect(pii &a, pii &b) {
//     return !(a.f < b.f && b.s < a.s || b.f < a.f && a.s < b.s);
// }

int n;
vvi edges;
vvi memo;

int solve(int l, int r) {
    if (l >= r) return 0;
    if (memo[l][r] >= 0) return memo[l][r];
    memo[l][r] = max(solve(l+1,r), solve(l, r-1));
    for (int k = l + 1; k <= r; k++) {
        if (edges[l][k]) {
            memo[l][r] = max(memo[l][r], 1 + solve(l+1, k-1) + solve(k+1,r));
        }
    }
    return memo[l][r];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    edges.resize(n, vi(n));
    memo.resize(n, vi(n, -1));
    forn(i, n) forn(j, n) cin >> edges[i][j];
    cout << solve(0, n-1) << "\n";

    // vvi dp(n, vi(n, 0));
    // for (int l = n - 1; l >= 0; l--) {
    //     for (int r = l + 1; r < n; r++) {
    //         // dp[l][r] = max({dp[l+1][r], dp[l][r-1], dp[l+1][r-1] + edges[l][r]});
    //         // if (edges[l][r]) {
    //         for (int k = l+1; k <= r; k++) {
    //             // dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][r]);
    //             if (edges[l][k]) 
    //                 dp[l][r] = max(
    //                     dp[l][r], 
    //                     ((l + 1 >= 0 && l + 1 < n) ? dp[l+1][k-1] : 0) + 
    //                     ((k + 1 < n) ? dp[k+1][r] : 0) + 1
    //                 );
    //         }
    //         // }
    //     }
    // }

    // cout << dp[0][n-1] << "\n";
    
    return 0;
}
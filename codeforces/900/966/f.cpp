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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, k; cin >> n >> k;
        vvi dp(n+1, vi(k+1, 1e9)), cost(n+1, vi(k+1, 1e9));
        for (int i = 1; i <= n; i++) {
            int a, b; cin >> a >> b;
            cost[i][0] = 0;
            for (int score = 1; score <= k; score++) {
                for (int rows = 0; rows <= score; rows++) {
                    int cols = score - rows;
                    if (rows > a || cols > b) continue;
                    cost[i][score] = min(cost[i][score], rows * b + cols * a - rows * cols); 
                }
            }
        }

        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int score = 1; score <= k; score++) {
            for (int i = 1; i <= n; i++) {
                for (int takeFromBefore = 0; takeFromBefore <= score; takeFromBefore++) {
                    dp[i][score] = min(dp[i][score], dp[i-1][takeFromBefore] + cost[i][score-takeFromBefore]);
                } 
            }
        }

        if (dp[n][k] == 1e9) cout << "-1\n";
        else cout << dp[n][k] << "\n";
    }
    return 0;
}
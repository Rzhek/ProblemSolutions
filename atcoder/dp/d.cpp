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
    int n, w; cin >> n >> w;
    vvl dp(n + 1, vl(w + 1, -1)); 
    forn (i, n + 1) dp[i][0] = 0;

    rep (i, 1, n + 1) {
        int weight, val; cin >> weight >> val;
        forn (j, w + 1) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (dp[i-1][j] >= 0 && j + weight <= w) {
                dp[i][j+weight] = max(dp[i][j+weight], dp[i-1][j] + val);
            } 
        }
    }
    // print2DArr(dp);
    cout << *max_element(all(dp.back())) << "\n";
    return 0;
}
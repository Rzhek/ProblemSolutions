#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
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
    
    string s; cin >> s;
    int n = sz(s);
    
    vi valid;
    forn (i, n / 2) {
        valid.pb(s[i] == s[n-i-1]);
    }
    n = n / 2;
    vvi dp(n + 1, vi(2, 1e9));
    dp[0][0] = 0;
    forn (i, n) {
        if (valid[i]) { 
            // skip 1 -> 1
            dp[i+1][0] = min(dp[i+1][0], dp[i][0]);
        } else if (i + 1 == n) { 
            // 00 -> 11 or 01 -> 11 wtf
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + 1);
        } else {
            if (!valid[i+1]) {
                // 00
                dp[i+1][0] = min(dp[i+1][0], dp[i][0] + 1);
                dp[i+2][0] = min(dp[i+2][0], dp[i][0] + 1);
            } else {
                // 01 -> 10
                dp[i+1][1] = min(dp[i+1][1], dp[i][0] + 1);
                // 01 -> 00 -> 11
                dp[i+2][0] = min(dp[i+2][0], dp[i][0] + 2);
            }
        }

        if (valid[i] && i + 1 < n) {
            if (!valid[i+1]) {
                dp[i+2][0] = min(dp[i+2][0], dp[i][1] + 1);
            } else {
                dp[i+1][1] = min(dp[i+1][1], dp[i][1] + 1);
            }
        }
    }

    cout << dp[n][0] << "\n";


    return 0;
}
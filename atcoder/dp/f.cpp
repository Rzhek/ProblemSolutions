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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vvi dp(n+1, vi(m+1, 0));

    rep (i, 1, n+1) {
        rep (j, 1, m + 1) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    string res;
    int i = n, j = m;
    while (i && j && dp[i][j]) {
        while (i && dp[i][j] == dp[i-1][j]) i--;
        while (j && dp[i][j] == dp[i][j-1]) j--;
        if (i && j && dp[i][j] != dp[i-1][j] && dp[i][j] != dp[i][j-1]) {
            res.pb(s[i-1]);
            i--;
            j--;
        }
    }

    reverse(all(res));
    cout << res << "\n";
    return 0;
}
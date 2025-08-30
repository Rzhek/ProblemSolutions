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
    tests {
        int n, m, k; cin >> n >> m >> k;
        string data; cin >> data;
        data = "L" + data;
        vi dp(n+2, 1e9);
        vi reachable(n+2, 0);
        dp[0] = 0; reachable[0] = 1;
        forn (i, n+1) {
            if (!reachable[i]) continue;
            if (data[i] == 'C') continue;
            if (data[i] == 'W') {
                dp[i+1] = min(dp[i+1], dp[i]+1);
                reachable[i+1] = 1;
            } else if (data[i] == 'L') {
                for (int j = 1; j <= m && i + j <= n+1; j++) {
                    dp[i+j] = min(dp[i+j], dp[i]);
                    reachable[i+j] = 1;
                }
            }
        }

        if (reachable[n+1] && dp[n+1] <= k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
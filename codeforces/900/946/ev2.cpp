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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        ll m, x; cin >> m >> x;
        vl dp(1e5+1, -1e18);

        dp[0] = 0;
        ll res = 0;
        forn(i, m) {
            ll cost, val; cin >> cost >> val;
            for (int j = min((ll)1e5 - val, res); j >= 0; j--) {
                if (dp[j] > -1e18 && dp[j] + i * x >= cost) {
                    dp[j+val] = max(dp[j+val], dp[j] - cost);
                    res = max(res, j + val);
                }
            }
        }
        cout << res << "\n";  
    }
    return 0;
}
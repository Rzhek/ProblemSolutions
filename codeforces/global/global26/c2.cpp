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
        int n; cin >> n;
        vi nums(n);
        forn (i, n) cin >> nums[i];

        vvl dp(n + 1, vl(2));
        dp[0] = {0, 0};

        for (int i = 1; i <= n; i++) {
            dp[i][0] = max({abs(dp[i-1][0] + nums[i-1]), abs(dp[i-1][1] + nums[i-1])});
            dp[i][1] = min({dp[i-1][0] + nums[i-1], dp[i-1][1] + nums[i-1]});
        }

        for (int i = 0; i <= n; i++) cout << dp[i][0] << " \n"[i==n];
        for (int i = 0; i <= n; i++) cout << dp[i][1] << " \n"[i==n];

        cout << dp[n][0] << "\n";


    }
    return 0;
}
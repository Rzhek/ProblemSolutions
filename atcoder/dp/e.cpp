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

const int maxVal = 1e5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll N, W; cin >> N >> W;
    vl dp(maxVal + 1, inf); dp[0] = 0;
    // dp[i] = j => value of i can be achieved by at least j weight

    forn (i, N) {
        int w, v; cin >> w >> v;
        for (int j = maxVal; j >= v; j--) {
            if (dp[j-v] != inf && dp[j-v] + w <= W) dp[j] = min(dp[j], dp[j-v]+w);
        }
    }
    int res = 0;
    forn (i, maxVal+1) if (dp[i] <= W) res = i;
    cout << res << "\n";

    return 0;
}
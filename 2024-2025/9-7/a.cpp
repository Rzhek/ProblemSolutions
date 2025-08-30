#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
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

const int maxn = 5e6+10;
int n, dp[maxn+1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    // dp[i] means that if intern 1 needs i minutes to complete some tasks,
    // intern 2 will need dp[i] minutes to complete the rest of them
    forn (ind, n) {
        int a, b; cin >> a >> b;
        for (int i = maxn; i >= a; i--) {
            dp[i] = min(dp[i-a], dp[i]+b);
            // dp[i-a] -> intern 1 completes the task, and intern 2 needs the same dp[i-a] minutes
            // dp[i]+b -> intern 2 completes the task, intern 1 still needs i minutes
        }
        // intern 1 cannot complete all tasks in [0, a) minutes, so intern 2 must do them
        for (int i = 0; i < a; i++) dp[i] += b;
    }
    int res = 1e9;
    forn (i, maxn) res = min(res, max(i, dp[i]));
    cout << res << "\n";

    return 0;
}
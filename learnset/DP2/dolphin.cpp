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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n; cin >> n;
        vi nums(n), bestL(n), bestR(n);
        forn (i, n) cin >> nums[i];

        vi dp;
        forn (i, n) {
            auto it = upper_bound(all(dp), nums[i]);
            if (it == dp.end()) dp.pb(nums[i]);
            else *it = nums[i];
            bestL[i] = dp.size();
        }

        dp.clear();
        reverse(all(nums));
        forn (i, n) {
            auto it = upper_bound(all(dp), nums[i]);
            if (it == dp.end()) dp.pb(nums[i]);
            else *it = nums[i];
            bestR[i] = dp.size();
        }

        reverse(all(bestR));

        int best = 1;
        forn (i, n) best = max(best, bestL[i] + bestR[i] - 1);
        cout << "Case " << tt << ":\n";
        cout << "Dynamo ate " << best << " food pellet(s)." << "\n\n";
    }

    return 0;
}
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

// void solve() {
//     int n; cin >> n;
//     vl nums(n), ans(n);
//     ll lcm = 1;
//     forn (i, n) {
//         cin >> nums[i];
//         lcm = lcm * nums[i] / __gcd(lcm, nums[i]);
//     }
//     ll sum = 0;
//     forn (i, n) {
//         ans[i] = lcm / nums[i];
//         sum += ans[i];
//     }
//     if (sum >= lcm) {
//         cout << "-1\n";
//     } else {
//         printArr(ans);
//     }
// }

int check(ll x, vl nums) {
    ll sum = 0;
    forn (i, nums.size()) {
        sum += x / nums[i] + (x % nums[i] != 0);
    }
    return sum < x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        // solve();
        int n; cin >> n;
        vl nums(n);
        forn (i, n) cin >> nums[i];
        ll ans = -1, lo = 1, hi = 1e9;
        while (lo <= hi) {
            ll m = (lo + hi) / 2;
            if (check(m, nums)) {
                ans = m;
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }
        if (ans == -1) {
            cout << "-1\n";
        } else {
            forn (i, n) {
                cout << (ans / nums[i] + (ans % nums[i] != 0)) << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
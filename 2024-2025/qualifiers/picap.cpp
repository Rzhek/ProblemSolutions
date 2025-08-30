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

int n, k;
vi nums;

int check(ll m) {
    int ind = 0;
    forn (i, k) {
        ll cur = 0;
        int numNames = 0;
        while (ind < n && cur + numNames + nums[ind] <= m) {
            cur += nums[ind];
            numNames++;
            ind++;
        }
        if (ind == n) return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    nums = vi(n);
    forn (i, n) cin >> nums[i];

    ll lo = 1, hi = 2e9;
    ll res = -1;
    while (lo <= hi) {
        ll m = (lo + hi) / 2;
        if (check(m)) {
            hi = m - 1;
            res = m;
        } else {
            lo = m + 1;
        }
    }

    cout << res << "\n";

    return 0;
}
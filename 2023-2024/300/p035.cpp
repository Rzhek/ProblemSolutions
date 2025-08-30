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

using ll = unsigned long long;
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
const long double EPS = 1e-9;

ll solve() {
    vi nums(3);
    forn (i, 3) cin >> nums[i];
    ll num; cin >> num;
    __uint128_t n = num;
    if (n == 2) return 0;
    __uint128_t res = n * (n * n + (n % 2 == 0 ? 6 * n - 16 : -1)) / 4;
    
    nums.erase(unique(all(nums)), nums.end());
    if (nums.size() == 1) res /= 6;
    if (nums.size() == 2) res /= 2;
    return (ll)res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << solve() << "\n";
    return 0;
}
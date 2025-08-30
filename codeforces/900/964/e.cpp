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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

const int maxn = 2e5+10;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vi sums(maxn, 0);
    for (int i = 1; i <= maxn; i++) sums[i] = (int)(log(i) / log(3) + 1 + EPS);
    for (int i = 2; i <= maxn; i++) sums[i] += sums[i-1];

    tests {
        int l, r; cin >> l >> r;
        ll res = 2 * (int)(log(l) / log(3) + 1 + EPS);
        res += sums[r] - sums[l];
        cout << res << "\n";
        
    }
    return 0;
}
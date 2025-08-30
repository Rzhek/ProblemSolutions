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

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; int t = 1;
    const ll maxi = 2'147'483'647;
    for (cin >> n; n != 0; cin >> n) {
        vl nums(n);
        forn (i, n) cin >> nums[i];
        ll res = nums[0];
        for (int i = 1; res <= maxi && i < n; i++) {
            res = lcm(res, nums[i]);
        }

        cout << t++ << ": ";
        if (res <= maxi) cout << "THE WORLD ENDS IN " << res << " DAYS\n";
        else cout << "NOT TO WORRY\n";
    }
    return 0;
}
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
    tests {
        ll n, m; cin >> n >> m;
        vi nums(n);
        forn (i, n) cin >> nums[i];
        map<ll, ll> cnt;
        forn (i, n) {
            cin >> cnt[nums[i]];
        }

        ll best = 0;
        for (auto [k, v] : cnt) {
            best = max(best, min(v, m / k) * k);
        }

        for (auto [k1, v1] : cnt) {
            ll k2 = k1+1;
            auto it = cnt.find(k2);
            ll v2 = it != cnt.end() ? it->second : 0;

            ll maxTake1 = min(v1, m / k1);
            ll maxTake2 = min(v2, (m - (maxTake1 * k1)) / k2);

            ll canSub = min({m - maxTake1 * k1 - maxTake2 * k2, maxTake1, v2 - maxTake2});
            best = max(best, maxTake1 * k1 + maxTake2 * k2 + canSub);
        }
        cout << best << "\n";


    }
    return 0;
}
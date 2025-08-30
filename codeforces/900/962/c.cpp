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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, q; cin >> n >> q;
        string a, b; cin >> a >> b;
        vvi have(1, vi(26, 0));
        vvi need(1, vi(26, 0));
        forn (i, n) {
            have.pb(have.back());
            need.pb(need.back());
            have.back()[a[i]-'a']++;
            need.back()[b[i]-'a']++;
        }

        forn (i, q) {
            int l, r; cin >> l >> r;
            int res = 0;
            forn (i, 26) {
                int totNeed = need[r][i] - need[l-1][i];
                int totHave = have[r][i] - have[l-1][i];
                res += max(0, totNeed-totHave);
            }
            cout << res << "\n";
        }
    }
    return 0;
}
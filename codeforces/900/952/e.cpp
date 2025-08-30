#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int x, y, z; cin >> x >> y >> z;
        ll k; cin >> k;
        ll res = 0;
        for (int xx = 1; xx <= x; xx++) {
            if (k % xx) continue;
            for (int yy = 1; yy <= y; yy++) {
                if ((k / xx) % yy) continue;
                ll zz = k / xx / yy;
                if (1 <= zz && zz <= z) {
                    ll waysToPutOnX = x - xx + 1;
                    ll waysToPutOnY = y - yy + 1;
                    ll waysToPutOnZ = z - zz + 1;
                    // cout << xx << " " << yy << " " << zz << "\n";
                    res = max(res, waysToPutOnX * waysToPutOnY * waysToPutOnZ);
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
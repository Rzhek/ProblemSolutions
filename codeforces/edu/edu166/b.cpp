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
        ll n; cin >> n;
        vi a(n), b(n+1);
        forn (i, n) cin >> a[i];
        forn (i, n+1) cin >> b[i];

        ll last = b[n];

        ll res = 0;
        ll append = 1e9;
        forn (i, n) {
            if (a[i] >= b[i]) {
                res += a[i] - b[i];
                if (a[i] >= last && last >= b[i]) append = 0;
                else append = min({append, abs(last - a[i]), abs(last - b[i])});
            } else if (a[i] < b[i]) {
                res += b[i] - a[i];
                if (b[i] >= last && last >= a[i]) append = 0;
                else append = min({append, abs(last - b[i]), abs(last - a[i])});
            } else {
                if (last == a[i]) append = 0;
                else append = min(append, abs(last - a[i]));
            }
        }

        // cout << res << " " << append << "\n";
        cout << res + append + 1 << "\n";


    }
    return 0;
}
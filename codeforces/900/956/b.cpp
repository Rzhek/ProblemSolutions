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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, m; cin >> n >> m;
        vi rows(n), cols(m);
        forn (r, n) forn (c, m) {
            char a; cin >> a; a -= '0';
            rows[r] += a;
            cols[c] += a;
        }
        forn (r, n) forn (c, m) {
            char a; cin >> a; a -= '0';
            rows[r] -= a;
            cols[c] -= a;
        }
        int works = 1;
        forn (r, n) works &= (rows[r] % 3 == 0);
        forn (c, m) works &= (cols[c] % 3 == 0);
        if (works) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
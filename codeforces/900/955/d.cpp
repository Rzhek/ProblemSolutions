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

int grid[501][501], type[501][501];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i <= 500; i++) memset(type[i], 0, sizeof(type[i]));
    tests {
        int n, m, k; cin >> n >> m >> k;
        ll diff = 0;
        forn (r, n) forn (c, m) cin >> grid[r+1][c+1];
        for (int r = 1; r <= n; r++) {
            string s; cin >> s;
            for (int c = 1; c <= m; c++) {
                type[r][c] = s[c-1]-'0';
                if (type[r][c]) diff += grid[r][c];
                else diff -= grid[r][c];
            }
        }
        for (int r = 1; r <= n; r++) for (int c = 1; c <= m; c++) type[r][c] += type[r][c-1];
        for (int c = 1; c <= m; c++) for (int r = 1; r <= n; r++) type[r][c] += type[r-1][c];

        ll gcd = 0;

        for (int r = k; r <= n; r++) {
            for (int c = k; c <= m; c++) {
                int num = type[r][c] - type[r-k][c] - type[r][c-k] + type[r-k][c-k];
                gcd = __gcd(gcd, (ll)k * k - 2 * num);
            }
        }

        if (diff == 0 || (gcd != 0 && diff % gcd == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
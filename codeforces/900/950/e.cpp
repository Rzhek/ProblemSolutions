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
        int n, m; cin >> n >> m;
        vvi a(n, vi(m)), b(n, vi(m));
        vpi data1(n * m + 1), data2(n * m + 1); 
        forn (r, n) forn (c, m) {
            cin >> a[r][c];
            data1[a[r][c]] = {r, c};
        }
        forn (r, n) forn (c, m) {
            cin >> b[r][c];
            data2[b[r][c]] = {r, c};
        }
        if (n == 1 || m == 1) {
            cout << "YES\n";
            continue;
        }
        vi colTransform(m, -1), rowTransform(n, -1);

        int works = 1;
        for (int i = 1; i <= n * m && works; i++) {
            auto [r1, c1] = data1[i];
            auto [r2, c2] = data2[i];

            if (rowTransform[r1] == -1 || rowTransform[r1] == r2) {
                rowTransform[r1] = r2;
            } else {
                works = 0;
            }
            if (colTransform[c1] == -1 || colTransform[c1] == c2) {
                colTransform[c1] = c2;
            } else {
                works = 0;
            }
        }

        // printArr(rowTransform);
        // printArr(colTransform);

        if (works) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
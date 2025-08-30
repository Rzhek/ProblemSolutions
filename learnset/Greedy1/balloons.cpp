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
    int n, a, b; cin >> n >> a >> b;
    while (n != 0 && a != 0 && b != 0) {
        int res = 0;
        vector<iii> data(n);
        forn (i, n) {
            int k, da, db; cin >> k >> da >> db;
            data[i] = {k, da, db};
        } 
        sort(all(data), [](auto &x, auto &y) {
            auto [k1, da1, db1] = x;
            auto [k2, da2, db2] = y;
            return (db1 - da1) < (db2 - da2);

        });


        for (auto [k, da, db] : data) {
            if (da == db) {
                res += k * da;
            } else if (da < db) {
                int take = min(a, k);
                a -= take;
                k -= take;
                res += take * da;

                take = min(b, k);
                b -= take;
                res += take * db;
            } else {
                int take = min(b, k);
                b -= take;
                k -= take;
                res += take * db;

                take = min(a, k);
                a -= take;
                res += take * da;
            }
        }

        cout << res << "\n";
        cin >> n >> a >> b;
    }

    return 0;
}
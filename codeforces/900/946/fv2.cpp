#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
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
        int r1 = 0, c1 = 0;
        int r2, c2, n, m; cin >> r2 >> c2 >> n >> m;
        r2--; c2--;
        set<pii> chips;
        vpi rows(n), cols(n);
        forn(i, n) {
            int r, c; cin >> r >> c;
            r--; c--;
            chips.emplace(r, c);
            rows[i] = {r, c};
            cols[i] = {r, c};
        }
        int rlo = 0, rhi = n - 1;
        int clo = 0, chi = n - 1;
        int alice = 0, bob = 0;
        sort(all(rows));
        sort(all(cols), [](auto a, auto b) {
            return a.s < b.s;
        });
        
        forn(i, m) {
            char move; cin >> move;
            int k; cin >> k;
            if (move == 'U') {
                r1 += k;
                while (rlo <= rhi && rows[rlo].f < r1) {
                    if (chips.count(rows[rlo])) {
                        if (i % 2) bob++;
                        else alice++;
                        chips.erase(rows[rlo]);
                    }
                    rlo++;
                }
            }
            if (move == 'D') {
                r2 -= k;
                while (rlo <= rhi && rows[rhi].f > r2) {
                    if (chips.count(rows[rhi])) {
                        if (i % 2) bob++;
                        else alice++;
                        chips.erase(rows[rhi]);
                    }
                    rhi--;
                }
            }
            if (move == 'L') {
                c1 += k;
                while (clo <= chi && cols[clo].s < c1) {
                    if (chips.count(cols[clo])) {
                        if (i % 2) bob++;
                        else alice++;
                        chips.erase(cols[clo]);
                    }
                    clo++;
                }
            }
            if (move == 'R') {
                c2 -= k;
                while (clo <= chi && cols[chi].s > c2) {
                    if (chips.count(cols[chi])) {
                        if (i % 2) bob++;
                        else alice++;
                        chips.erase(cols[chi]);
                    }
                    chi--;
                }
            }
        }

        cout << alice << " " << bob << "\n";
        
    }
    return 0;
}
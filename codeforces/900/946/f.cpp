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
        int a, b, n, m; cin >> a >> b >> n >> m;
        vpi down, up, left, right;
        forn(i, n) {
            int r, c; cin >> r >> c;
            r--; c--;
            up.emplace_back(r, c);
            left.emplace_back(r, c);
        }

        sort(all(up), [](pii x, pii y) {
            return x.f > y.f;
        });
        sort(all(left), [](pii x, pii y) {
            return x.s > y.s;
        });

        down = up;
        right = left;
        reverse(all(down));
        reverse(all(right));

        int alice = 0, bob = 0;
        int r1 = 0, r2 = a, c1 = 0, c2 = b;
        forn(i, m) {
            char move; cin >> move;
            int k; cin >> k;

            switch (move) {
            case 'U':
                while (up.size() && up.back().f < r1 + k) {
                    auto [r, c] = up.back();
                    up.pop_back();
                    if (r < r1 || !(c1 <= c && c < c2)) continue;
                    if (i & 1) bob++;
                    else alice++;
                }
                r1 += k;
                break;
            case 'D':
                while (down.size() && down.back().f >= r2 - k) {
                    auto [r, c] = down.back();
                    down.pop_back();
                    if (r >= r2 || !(c1 <= c && c < c2)) continue;
                    if (i & 1) bob++;
                    else alice++;
                }
                r2 -= k;
                break;
            case 'L':
                while (left.size() && left.back().s < c1 + k) {
                    auto [r, c] = left.back();
                    left.pop_back();
                    if (c < c1 || !(r1 <= r && r < r2)) continue;
                    if (i & 1) bob++;
                    else alice++;
                }
                c1 += k;
                break;
            case 'R':
                while (right.size() && right.back().s >= c2 - k) {
                    auto [r, c] = right.back();
                    right.pop_back();
                    if (c >= c2 || !(r1 <= r && r < r2)) continue;
                    if (i & 1) bob++;
                    else alice++;
                }
                c2 -= k;
                break;
            }
            
        }
        cout << alice << " " << bob << "\n";
    }
    return 0;
}
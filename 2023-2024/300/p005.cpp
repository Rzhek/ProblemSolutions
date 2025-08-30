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
    ll a, b, n; cin >> a >> b >> n;
    n++;
    ll x1, x2, y1, y2;
    ll x = -1;
    while (1) {
        ll y = a * (x + 1) / b;
        int colisions = (x + 1) / 2 + (y + 1) / 2;
        if (colisions > n) break;
        if (colisions == n) {
            if ((x - 1) % 4 == 0) {
                x1 = 1;
                x2 = 1;
            } else {
                x1 = -1;
                x2 = 1;
            }
            // cout << x << " " << y << "\n";
            if ((y + 1) % 4 <= 1) {
                // dont change
                // cout << "dont change\n";
                y2 = b;
                y1 = a * (x + 1);
                while (y1 > y2) y1 -= 2 * y2;
            } else {
                // change
                // cout << "change\n";
                y2 = b;
                y1 = a * (x + 1);
                while (y1 > y2) y1 -= 2 * y2;
                y1 = -y1;
            }
            int gcd = __gcd(y1, y2);
            y1 /= gcd;
            y2 /= gcd;
            if (y1 == 0) y2 = 1;
            cout << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";
            return 0;
        }
        x += 2;
    }

    ll y = 1;
    while (1) {
        ll x = (b * y - a) / a;
        int colisions = (x + 1) / 2 + (y + 1) / 2;
        if (colisions > n) break;
        if (colisions == n) {
            if ((y - 1) % 4 == 0) {
                y1 = 1;
                y2 = 1;
            } else {
                y1 = -1;
                y2 = 1;
            }
            // cout << x << " " << y << "\n";
            if ((x + 1) % 4 <= 1) {
                // dont change
                // cout << "dont change\n";
                x2 = a;
                x1 = b * y - a;
                while (x1 > x2) x1 -= 2 * x2;
            } else {
                // change
                // cout << "change\n";
                x2 = a;
                x1 = b * y - a;
                while (x1 > x2) x1 -= 2 * x2;
                x1 = -x1;
            }
            int gcd = __gcd(x1, x2);
            x1 /= gcd;
            x2 /= gcd;
            if (x1 == 0) x2 = 1;
            if (x2 < 0) {
                x1 = -x1;
                x2 = -x2;
            }
            cout << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";
            return 0;
        }
        y += 2;
    }

    assert(0);
    return 0;
}
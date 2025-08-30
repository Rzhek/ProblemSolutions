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

struct P {
    ll x, y;
    P(ll x, ll y) : x(x), y(y) {}
    ll cross(P p) {
        return x * p.y - y * p.x;
    }
    P operator-(P p) {
        return {x - p.x, y - p.y};
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        vector<P> pts;
        for (int i = 0; i < 3; i++) {
            ll x, y; cin >> x >> y;
            pts.emplace_back(x, y); 
        }
        ll res = (pts[1]-pts[0]).cross(pts[2]-pts[0]);
        if (res == 0) {
            cout << "TOUCH\n";
        } else if (res < 0) {
            cout << "RIGHT\n";
        } else {
            cout << "LEFT\n";
        }
    }
    return 0;
}
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

void solve() {
    int lo = 0, hi = 1000;
    while (hi - lo > 1) {
        int x = (lo * 2 + hi) / 3;
        int y = (lo + 2 * hi) / 3;
        cout << "? " << x << " " << y << endl;
        int a; cin >> a;

        if (a == x * y) lo = y;
        else if (a == x * (y + 1)) lo = x, hi = y;
        else hi = x;
    }
    cout << "! " << hi << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        solve();
    }
    return 0;
}
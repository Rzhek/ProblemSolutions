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

int check(int n, int k, int v) {
    n -= v;
    int c = k;
    while (v / k && n > 0) {
        n -= v / k;
        k *= c;
    }
    return n <= 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int lo = 1, hi = n;
    int res = -1;

    while (lo <= hi) {
        int m = (lo + hi) / 2;
        int ans = check(n, k, m);
        if (ans) {
            res = m;
            hi = m - 1; 
        } else {
            lo = m + 1;
        }
    }

    cout << res << "\n";

    return 0;
}
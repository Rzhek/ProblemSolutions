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

pll solve(vl &a, vl &b, int n, int k, int m) {
    ll count = 0;
    ll tmp = 0;
    forn (i, n) {
        ll diff = max(0ll, a[i] - m);
        ll num = diff / b[i] + (a[i] >= m);
        count += num;
        tmp += num * a[i] - num * (num - 1) / 2 * b[i];
    }
    if (count > k) {
        tmp -= (count-k) * m;
    }
    return {count, tmp};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, k; cin >> n >> k;
        vl a(n), b(n);
        forn (i, n) cin >> a[i];
        forn (i, n) cin >> b[i];

        int lo = 0, hi = 1e9+100;
        while (lo < hi - 1) {
            int m = (lo + hi) / 2;
            if (solve(a, b, n, k, m).f < k) {
                hi = m;
            } else {
                lo = m;
            }
        }

        cout << solve(a, b, n, k, lo).s << "\n";

    }
    return 0;
}
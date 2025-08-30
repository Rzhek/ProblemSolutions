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
    int n; cin >> n;
    vl sums(n+1), sorted(n+1);
    forn (i, n) cin >> sums[i+1], sorted[i+1] = sums[i+1];

    sort(sorted.begin() + 1, sorted.end());
    partial_sum(sorted.begin() + 1, sorted.end(), sorted.begin() + 1);
    partial_sum(sums.begin() + 1, sums.end(), sums.begin() + 1);
    
    int q; cin >> q;
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            cout << sums[r] - sums[l-1] << "\n";
        } else {
            cout << sorted[r] - sorted[l-1] << "\n";
        }
    }

    return 0;
}
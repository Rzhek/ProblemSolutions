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

void move(int n, ll &k, int from, int to) {
    if (n == 0) return;
    // we can assume we did all those operations
    if ((1ll << n) - 1 < k) {
        k -= (1ll << n) - 1;
        return;
    }
    // we need to move n - 1 disks from from to a free one
    move(n - 1, k, from, 3 - from - to);
    // then move nth to to
    k--;
    if (k == 0) {
        cout << n << " " << (char)('A' + from) << " " << (char)('A' + to) << "\n";
        k = 4e18;
    } 
    // and move n - 1 disks to to
    move(n - 1, k, 3 - from - to, to);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int t = 1;; t++) {
        ll k, n; cin >> k >> n;
        if (!k && !n) return 0;
        cout << "Case " << t << ": ";
        move(n, k, 0, 2);
    }
    return 0;
}
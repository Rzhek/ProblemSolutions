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

const int maxn = 2e5+10;
int n, a[maxn];
vi children[maxn];

ll solve(int u) {
    if (children[u].size() == 0) return a[u];
    ll mini = inf;
    for (int v : children[u]) {
        mini = min(mini, solve(v));
    }
    if (u == 1) return a[1] + mini;
    return min(mini, (a[u] + mini) / 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 2; i <= n; ++i) {
            int par; cin >> par;
            children[par].pb(i);
        }
        cout << solve(1) << "\n";
        for (int i = 1; i <= n; i++) children[i].clear();
    }
    return 0;
}
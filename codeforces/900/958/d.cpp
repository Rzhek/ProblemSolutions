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

const int rounds = 20;

ll solve(int u, int par, int round, vl &a, vvi &edges, vvl &dp) {
    if (dp[u][round] != inf) return dp[u][round];
    dp[u][round] = a[u] * (round+1);

    for (int v : edges[u]) {
        if (v == par) continue;
        ll tmp = inf;
        for (int r = 0; r < rounds; r++) {
            if (r == round) continue;
            tmp = min(tmp, solve(v, u, r, a, edges, dp));
        }
        dp[u][round] += tmp;
    }
    return dp[u][round];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vl a(n);
        forn (i, n) cin >> a[i];
        vvi edges(n);
        forn (i, n - 1) {
            int u, v; cin >> u >> v;
            u--; v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vvl dp(n, vl(rounds, inf));
        forn (i, rounds) solve(0, -1, i, a, edges, dp);
        cout << *min_element(all(dp[0])) << "\n";
    }
    return 0;
}
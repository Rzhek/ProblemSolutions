#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
#define forn(i, n) for (int i = 0; i < n; ++i)
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
const int mod2inv = 500000004;
const long double EPS = 1e-9;

const int maxn = 5e4 + 10;
bitset<maxn> res[maxn];
vi adj[maxn];
int in_deg[maxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[v].push_back(u);
        in_deg[u]++;
    }

    queue<int> q;
    forn (i, n) {
        if (in_deg[i] == 0) q.push(i);
        res[i][i] = 1;
    }

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            res[v] |= res[u];
            if (!--in_deg[v]) q.push(v);
        }
    }

    forn (i, n) cout << res[i].count() << " "; cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
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

int n, m; 
vvi edges;
vi par, dist;

int dfs(int u, int w, set<int> &path) {
    if (u == n - 1) return 1;
    if (path.find(u) != path.end()) return 0;

    path.insert(u);
    for (int v : edges[u]) {
        if (dist[v] >= w + 1) continue;
        dist[v] = w + 1;
        par[v] = u;
        if (!dfs(v, w + 1, path)) return 0;
    }

    path.erase(u);
    return 1;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    edges.resize(n);
    par.resize(n, -1);
    dist.resize(n, 0);

    forn (i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
    }

    set<int> path;
    int ans = dfs(0, 0, path);

    if (!ans || par[n-1] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vi res;
    int cur = n - 1;
    while (cur != -1) {
        res.pb(cur);
        cur = par[cur];
    }

    reverse(all(res));
    cout << res.size() << "\n";
    for (int x : res) {
        cout << x + 1 << " ";
    }
    cout << "\n";

    return 0;
}
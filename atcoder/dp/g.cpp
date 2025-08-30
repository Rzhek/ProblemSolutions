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

int n, m; 
vvi edges;
vi dist;
vi visited;

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = 1;
    for (int v : edges[u]) {
        dfs(v);
        dist[u] = max(dist[u], dist[v]+1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    edges = vvi(n);
    dist = vi(n, 0);
    visited = vi(n, 0);
    dist[n-1] = 0;

    forn (i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[u].pb(v);
    }

    forn (i, n) {
        dfs(i);
    }

    // printArr(dist);
    // printArr(visited);
    cout << *max_element(all(dist)) << "\n";

    return 0;
}
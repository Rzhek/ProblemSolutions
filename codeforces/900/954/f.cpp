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


int timer;
vi disc, low, visited;
vpi bridges;
vvi edges;
void dfs(int u = 0, int p = 0){
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    for(int v : edges[u]){
        if(v != p){
            if(visited[v]) low[u] = min(low[u], disc[v]);
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > disc[u])
                    bridges.push_back({u, v});
            }
        }
    }
}

void getSize(vvi &edges, vi &sizes, int u) {
    if (sizes[u]) return; // if visited
    sizes[u] = 1;

    for (auto v : edges[u]) {
        if (!sizes[v]) { // if not visited
            getSize(edges, sizes, v);
            sizes[u] += sizes[v];
        }
    } 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, m; cin >> n >> m;
        edges = vvi(n);
        disc = vi(n, 0);
        low = vi(n, 0);
        visited = vi(n, 0);
        timer = 0;
        bridges.clear();
        forn (i, m) {
            int u, v; cin >> u >> v;
            u--; v--;
            edges[u].pb(v);
            edges[v].pb(u);
        }
        dfs();

        vi sizes(n, 0);
        // Graph is fully connected via undirected edges
        getSize(edges, sizes, 0);

        ll res = (ll)n * (n - 1) / 2;

        // printArr(sizes);
        
        for (auto [u, v] : bridges) {
            ll sz2 = min(sizes[u], sizes[v]);
            ll sz1 = n - sz2;
            // cout << u << " " << v << " " << sz1 << " " << sz2 << "\n";
            res = min(res, sz1 * (sz1-1) / 2 + sz2 * (sz2-1) / 2);
        }
        cout << res << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
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

struct lift {
    vi d, p, j;
    lift(vector<vi>& adj) : d(sz(adj)), p(d), j(d) {
        dfs(0, adj);
    }
    void dfs(int u, vector<vi>& adj) {
        int jmp = (d[u] + d[j[j[u]]] == 2 * d[j[u]]) ? j[j[u]] : u;
        for (int v : adj[u])
            if (v != p[u])
                d[v] = d[p[v] = u] + 1, j[v] = jmp, dfs(v, adj);
    }
    int lca(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        while (d[u] > d[v]) u = d[j[u]] >= d[v] ? j[u] : p[u];
        if (u == v) return u;
        while (p[u] != p[v])
            if (j[u] != j[v]) u = j[u], v = j[v];
            else u = p[u], v = p[v];
        return p[u];
    }
    int kth(int u, int k) {
        if (k > d[u]) return -1;
        k = d[u] - k;
        while (d[u] > k) u = d[j[u]] >= k ? j[u] : p[u];
        return u;
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vvi edges(n);
        forn(i, n - 1) {
            int a, b; cin >> a >> b;
            a--; b--;
            edges[a].pb(b);
            edges[b].pb(a);
        }
        lift lft(edges);
        vi perm(n);
        int valid = 1;
        forn(i, n) cin >> perm[i], perm[i]--;
        forn(i, n - 1) {
            int a = perm[i], b = perm[i+1];
            int lca = lft.lca(a, b);
            int dist = lft.d[a] + lft.d[b] - 2 * lft.d[lca];
            if (dist > 3) {
                valid = 0;
                break;
            }
        }
        cout << valid << "\n";
    }
    return 0;
}
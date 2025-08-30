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
    int distance(int u, int v) {
        int l = lca(u, v);
        return d[u] + d[v] - 2 * d[l];
    }
};

const int maxn = 2e5+5; // or whatever the upper bound is
int fen[maxn];
inline void add(int p, int val) { // make sure to convert to 1 base index
    // otherwise uncomment
    for (p++; p < maxn; p += p&-p) fen[p] ^= val;
}
inline int get(int p) { // inclusive [0, p]
    int res = 0;
    for (; p; p -= p&-p) res ^= fen[p];
    return res;
}
inline int get(int a, int b) { // [a, b]
    return get(b+1) - get(a);
}

void calcVals(vvi &edges, vi &a) {
    // find bitwise xor bettween root and each element
    int n = edges.size();
    vi visited(n, 0);
    queue<pii> q;
    q.push({0, 0});
    while (q.size()) {
        auto [u, w] = q.front();
        q.pop();
        add(u, w ^ a[u]);
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v]) continue;
            q.push({v, w ^ a[u]});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vi a(n);
    vvi edges(n);
    forn (i, n) cin >> a[i];
    forn (i, n-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    lift lift(edges);
    calcVals(edges, a);

    for (int i = 0; i < n; i++) {
        cout << i << ": " << get(i, i) << "\n";
    }
    
    while (q--) {

    }

    
    return 0;
}
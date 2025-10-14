#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

struct Dinic
{
    struct Edge
    {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); }
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0)
    {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f)
    {
        if (v == t || !f)
            return f;
        for (int &i = ptr[v]; i < sz(adj[v]); i++)
        {
            Edge &e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c)))
                {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t)
    {
        ll flow = 0;
        q[0] = s;
        rep(L, 0, 31) do
        {
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t])
            {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX))
                flow += p;
        }
        while (lvl[t])
            ;
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

typedef array<ll, 3> Edge;
vector<Edge> gomoryHu(int N, vector<Edge> ed)
{
    vector<Edge> tree;
    vi par(N);
    rep(i, 1, N)
    {
        Dinic D(N);
        for (Edge t : ed)
            D.addEdge(t[0], t[1], t[2], t[2]);
        tree.push_back({i, par[i], D.calc(i, par[i])});
        rep(j, i + 1, N) if (par[j] == par[i] && D.leftOfMinCut(j)) par[j] = i;
    }
    return tree;
}
ll res = 0;
vector<vector<pii>> adj;

void solve(int u, int p, int cur) {
    if (p != -1) res += cur;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        solve(v, u, min(cur, w));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<Edge> edges;
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges.push_back({u, v, 1});
    }

    adj = vector<vector<pii>>(n);
    for (auto [u, v, w] : gomoryHu(n, edges)) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int u = 0; u < n; u++) solve(u, -1, 1e9);
    cout << res / 2 << "\n";
}
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)

using ll = long long;
using vi = vector<int>;

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); }
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        } 
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L, 0, 31) do {
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int convert(int r, int c, int t) {
    return r * 100 + c * 10 + t;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    Dinic dinic(1000 + 2);
    int s = 1000, sink = s + 1;

    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            for (int t = 0; t < 10; t++) {
                if (r == 0) dinic.addEdge(convert(r,c,t), sink, 1);
                else dinic.addEdge(convert(r,c,t), convert(r-1,c,t), 1);
                
                if (r == 9) dinic.addEdge(convert(r,c,t), sink, 1);
                else dinic.addEdge(convert(r,c,t), convert(r+1,c,t), 1);
                
                if (c == 0) dinic.addEdge(convert(r,c,t), sink, 1);
                else dinic.addEdge(convert(r,c,t), convert(r,c-1,t), 1);
                
                if (c == 9) dinic.addEdge(convert(r,c,t), sink, 1);
                else dinic.addEdge(convert(r,c,t), convert(r,c+1,t), 1);
                
                if (t == 0) dinic.addEdge(convert(r,c,t), sink, 1);
                else dinic.addEdge(convert(r,c,t), convert(r,c,t-1), 1);
                
                if (t == 9) dinic.addEdge(convert(r,c,t), sink, 1);
                else dinic.addEdge(convert(r,c,t), convert(r,c,t+1), 1);
                
            }
        }
    }

    while (n--) {
        int r, c, t; cin >> r >> c >> t;
        dinic.addEdge(s, convert(r,c,t), LLONG_MAX);
    }

    cout << dinic.calc(s, sink) << "\n";
}
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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt; cin >> tt;
    for (int tc = 1 ; tc <= tt; tc++) {
        int n; cin >> n;
        vector<array<int, 4>> pts(n);
        for (auto &[x, y, r, c] : pts) cin >> x >> y >> r >> c;
        
        int s = n, t = s + 1;
        Dinic dinic(n + 2);

        int totalPos = 0;

        for (int i = 0; i < n; i++) {
            if (pts[i][3] >= 0) dinic.addEdge(s, i, pts[i][3]), totalPos += pts[i][3];
            else dinic.addEdge(i, t, -pts[i][3]);
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (i != j) {
                auto [x1, y1, r1, c1] = pts[i];
                auto [x2, y2, r2, c2] = pts[j];

                int dx = x1 - x2, dy = y1 - y2;
                if (dx * dx + dy * dy <= r1 * r1) {
                    dinic.addEdge(i, j, (ll)1e9);
                }
            }
        }

        cout << "Case #" << tc << ": " << totalPos - dinic.calc(s, t) << "\n";
    }
}
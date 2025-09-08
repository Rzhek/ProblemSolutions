#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

struct DSU {
    int n;
    vi p;
    
    DSU(int n): n(n) {
        p = vi(n);
        iota(p.begin(), p.end(), 0);
    }

    int par(int u) {
        if (u == p[u]) return u;
        return p[u] = par(p[u]);
    }

    bool merge(int u, int v) {
        int p1 = par(u), p2 = par(v);
        if (p1 == p2) return false;
        p[u] = p2;
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, r; cin >> n >> m >> r;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        dsu.merge(u, v);
    }

    vector<array<int, 3>> edges(n);

    for (int i = 0; i < r; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[i] = {w, u, v};
    }

    sort(edges.begin(), edges.end());

    long long cost = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.merge(u, v)) cost += w;
    }

    cout << cost << "\n";

}
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

struct DSU {
    int n;
    vi par, sz;
    DSU(int n): n(n), par(vi(n)), sz(vi(n, 1)) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int i) {
        if (i == par[i]) return i;
        return par[i] = find(par[i]);
    }

    bool join(int u, int v) {
        int p1 = find(u);
        int p2 = find(v);
        if (p1 == p2) return false;
        if (sz[p1] < sz[p2]) swap(p1, p2);
        par[p2] = p1;
        sz[p1] += sz[p2];
        return true;
    } 
};

void dfs(int u, int p, vector<vector<pii>> &adj, vi &depth, vector<vi> &jump, vector<vi> &maxi) {
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        jump[0][v] = u;
        maxi[0][v] = w;
        dfs(v, u, adj, depth, jump, maxi);
    }
}

int binlift(int u, int v, vi &depth, vector<vi> &jump, vector<vi> &maxi) {
    if (depth[u] < depth[v]) swap(u, v);
    int res = 0;
    for (int i = 0; i < 20; i++) {
        if ((depth[u]-depth[v]) & (1 << i)) {
            res = max(res, maxi[i][u]);
            u = jump[i][u];
        }
    }
    assert(depth[u] == depth[v]);
    if (u == v) return res;

    for (int i = 19; i >= 0; i--) {
        if (jump[i][u] != jump[i][v]) {
            res = max({res, maxi[i][u], maxi[i][v]});
            u = jump[i][u];
            v = jump[i][v];
        }
    }
    assert(u != v && jump[0][u] == jump[0][v]);
    return res = max({res, maxi[0][u], maxi[0][v]});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    vector<vi> jump(20, vi(n, -1)), maxi(20, vi(n));
    vector<vector<pii>> adj(n);
    vi depth(n);
    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (dsu.join(u, v)) {
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (jump[0][i] != -1) continue;
        jump[0][i] = i;
        dfs(i, -1, adj, depth, jump, maxi);
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            jump[j][i] = jump[j-1][jump[j-1][i]];
            maxi[j][i] = max(maxi[j-1][i], maxi[j-1][jump[j-1][i]]);
        }
    }

    while (q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (u == v) {
            cout << "0\n";
        } else if (dsu.find(u) != dsu.find(v)) {
            cout << "-1\n";
        } else {
            cout << binlift(u, v, depth, jump, maxi) + 1 << "\n";
        }
    }
}
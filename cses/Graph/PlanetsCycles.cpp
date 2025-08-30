#include <bits/stdc++.h>
using namespace std;

namespace SCCTarjan {
    vector<int> val, comp, z, cont;
    int Time, ncomps;
    template<class G, class F> int dfs(int j, G& g, F& f) {
        int low = val[j] = ++Time, x;
        z.push_back(j);
        for (auto e : g[j])
            if (comp[e] < 0) low = min(low, val[e] ?: dfs(e, g, f));
        if (low == val[j]) {
            do {
                x = z.back();
                z.pop_back();
                comp[x] = ncomps;
                cont.push_back(x);
            } while (x != j);
            f(cont);
            cont.clear();
            ncomps++;
        }
        return val[j] = low;
    }
    template<class G, class F> vector<int> scc(G &g, F f) {
        int n = g.size();
        val.assign(n, 0);
        comp.assign(n, -1);
        Time = ncomps = 0;
        for (int i = 0; i < n; i++)
            if (comp[i] < 0) dfs(i, g, f);
        return comp;
    }
    template<class G>
    vector<int> scc(G &g) {
        return scc(g, [](auto &v) {});
    }
}

void dfs(int u, vector<int> &adj, vector<int> &sz, vector<int> &visited) {
    if (visited[u]) return;
    visited[u] = 1;
    if (adj[u] != -1) {
        dfs(adj[u], adj, sz, visited);
        sz[u] += sz[adj[u]];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; u++) {
        int v; cin >> v; v--;
        adj[u].push_back(v);
    }

    vector<int> scc = SCCTarjan::scc(adj);
    int m = SCCTarjan::ncomps;
    vector<int> sz(m), visited(m);

    for (int u = 0; u < n; u++) {
        sz[scc[u]]++;
    }

    vector<int> m_adj(m, -1);
    for (int u = 0; u < n; u++) {
        if (scc[u] != scc[adj[u][0]]) {
            m_adj[scc[u]] = scc[adj[u][0]];
        }
    }

    for (int u = 0; u < m; u++) {
        dfs(u, m_adj, sz, visited);
    }

    for (int i = 0; i < n; i++) {
        cout << sz[scc[i]] << " ";
    }
    cout << "\n";


}
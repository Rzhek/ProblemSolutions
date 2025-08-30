#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

void solve(int u, vector<ll> &dp, vector<set<int>> &adj, vector<ll> &vals) {
    if (dp[u]) return;

    for (int v : adj[u]) {
        solve(v, dp, adj, vals);
        dp[u] = max(dp[v], dp[u]);
    }
    dp[u] += vals[u];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];

    vector<vector<int>> adj(n);
    while (m--) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }

    vector<int> scc = SCCTarjan::scc(adj);
    int metaN = SCCTarjan::ncomps;

    vector<ll> meta_vals(metaN);
    for (int i = 0; i < n; i++) {
        meta_vals[scc[i]] += vals[i];
    }

    vector<ll> dp(metaN);
    vector<set<int>> meta_adj(metaN);

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v] && meta_adj[scc[u]].count(scc[v]) == 0) {
                meta_adj[scc[u]].insert(scc[v]);
            }
        }
    }

    for (int u = 0; u < metaN; u++) {
        solve(u, dp, meta_adj, meta_vals);
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";


}
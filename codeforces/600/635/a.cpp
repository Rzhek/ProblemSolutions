#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
vector<vector<ll>> edges;
vector<ll> subTreeSize, visited, profit;
 
void dfs(ll u, ll depth) {
    visited[u] = 1;
    for (ll v : edges[u]) {
        if (visited[v]) continue;
        dfs(v, depth + 1);
        subTreeSize[u] += subTreeSize[v];
    }
    profit.push_back(depth - subTreeSize[u]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    edges.resize(n);
    visited.resize(n, 0);
    subTreeSize.resize(n, 1);
 
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
 
    dfs(0, 1);
    sort(profit.rbegin(), profit.rend());
 
    ll res = 0;
    for (int i = 0; i < k; i++) {
        res += profit[i];
    }
    cout << res << '\n';   
    return 0;
}
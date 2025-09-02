#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    while (m--) {
        int u, v; cin >>u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sizes, vis(n);

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        int sz = 0;
        queue<int> q({i});
        while (q.size()) {
            int u = q.front();
            q.pop();
            sz++;

            for (int v : adj[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }

        sizes.push_back(sz);
    }

    bitset<int(1e5+1)> dp;
    dp[0] = 1;
    
    for (auto sz : sizes) {
        dp |= dp << sz;
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << "";
    }
    cout << "\n";
}
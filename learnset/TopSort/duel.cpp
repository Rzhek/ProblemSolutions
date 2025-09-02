#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    for (cin >> n >> m; n && m; cin >> n >> m) {
        vector<vector<int>> edges(n);
        vector<int> visited(n), indegree(n);
        while (m--) {
            int u, v; cin >> u >> v;
            u--; v--;
            edges[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) if (!indegree[i]) q.push(i);
        int many = 0;

        while (q.size()) {
            many |= q.size() > 1;
            auto u = q.front();
            visited[u] = 1;
            q.pop();
            for (int v : edges[u]) {
                indegree[v]--;
                if (!indegree[v]) q.push(v);
            }
        }

        if (accumulate(visited.begin(), visited.end(), 0) == n) {
            cout << 1 + many << "\n";
        } else cout << 0 << "\n";
    }


    return 0;
}
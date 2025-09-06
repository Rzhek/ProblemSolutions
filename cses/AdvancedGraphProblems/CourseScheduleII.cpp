#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vvi rev_adj(n);
    vi outdeg(n), res;
    res.reserve(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        rev_adj[v].push_back(u);
        outdeg[u]++;
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) if (outdeg[i] == 0) pq.push(i);

    while (pq.size()) {
        int u = pq.top();
        pq.pop();

        res.push_back(u);
        for (auto v : rev_adj[u]) if (--outdeg[v] == 0) pq.push(v);
    }

    for (int i = n - 1; i >= 0; --i) cout << res[i] + 1 << " "; cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void dfs(int u, int p, vector<vi> &adj, vi &leaves) {
    if (adj[u].size() == 1) {
        leaves.push_back(u);
    }
    for (int v : adj[u]) if (v != p) {
        dfs(v, u, adj, leaves);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vi> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi leaves;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() != 1) {
            dfs(i, -1, adj, leaves);
            break;
        }
    }

    cout << (leaves.size() / 2 + (leaves.size() % 2)) << "\n";
    for (int i = 0; i < leaves.size() / 2; i++) {
        cout << leaves[i] + 1 << " " << leaves[leaves.size() / 2 + i] + 1 << "\n";
    }
    if (leaves.size() % 2) cout << leaves[0] + 1 << " " << leaves[leaves.size() - 1] + 1 << "\n";
}
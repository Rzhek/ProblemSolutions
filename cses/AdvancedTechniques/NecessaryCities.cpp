#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pair<int, int>>;

void dfs(int u, int p, vvi& adj, vi& disc, vi& low, vi& isCut, int& time) {
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u]) {
        if (v == p) continue;

        if (disc[v] == -1) { // If v is not visited
            children++;
            dfs(v, u, adj, disc, low, isCut, time);
            low[u] = min(low[u], low[v]);

            // Cut Node condition
            if (p != -1 && low[v] >= disc[u]) {
                isCut[u] = 1;
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }

    // Root condition
    if (p == -1 && children > 1) {
        isCut[u] = 1;
    }
}

vi getCutVertices(int n, vvi& adj) {
    vi disc(n, -1), low(n, -1), isCut(n, 0);
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1, adj, disc, low, isCut, time);
        }
    }

    vi res;
    for (int i = 0; i < n; i++) {
        if (isCut[i]) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vvi adj(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi cutNodes = getCutVertices(n, adj);
    cout << cutNodes.size() << "\n";
    for (int u : cutNodes) {
        cout << u + 1 << " ";
    }
    cout << "\n";
}
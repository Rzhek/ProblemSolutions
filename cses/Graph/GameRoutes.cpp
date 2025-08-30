#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
using ll = long long;
const int maxn = 1e5+5;
int n, m, indeg[maxn];
ll ways[maxn];
vector<int> adj[maxn];


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    ways[0] = 1;
    while (m--) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!indeg[i]) q.push(i);
    }

    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            ways[v] += ways[u];
            ways[v] %= MOD;
            if (!--indeg[v]) {
                q.push(v);
            }
        }
    }

    cout << ways[n-1] << "\n";
}
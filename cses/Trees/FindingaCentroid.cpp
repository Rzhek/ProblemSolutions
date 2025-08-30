#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int n, sz[maxn], res = -1;
vector<int> adj[maxn];

void dfs(int u = 0, int p = -1) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    if (sz[u] * 2 < n || res != -1) return;
    int works = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        works &= sz[v] <= n / 2;
    }
    if (works) res = u;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();
    cout << res + 1 << "\n";
}
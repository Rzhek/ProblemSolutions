#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5, maxk = 20;
int nxt[maxn], isCycle[maxn], vis[maxn], cur[maxn], whichRoot[maxn], depth[maxn], cycleRoot[maxn], depthCycle[maxn], szCycle[maxn], lift[maxn][maxk];
vector<int> pre[maxn];

void dfsCycle(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    if (cur[nxt[u]] || nxt[u] == u) {
        isCycle[nxt[u]] = 1;
        return;
    }
    cur[u] = 1;
    dfsCycle(nxt[u]);
    cur[u] = 0;
}

void dfsDepth(int u, int d, int root) {
    if (isCycle[u] && d) return;
    depth[u] = d;
    whichRoot[u] = root;
    for (int v : pre[u]) {
        dfsDepth(v, d + 1, root);
    }
}

int lca(int u, int v) {
    int diff = depth[u] - depth[v];
    for (int i = 0; i < maxk; i++) {
        if (diff & (1 << i)) u = lift[u][i];
    }
    if (u == v) return u;

    for (int i = maxk - 1; i >= 0; i--) {
        if (lift[u][i] != lift[v][i]) {
            u = lift[u][i];
            v = lift[v][i];
        }
    }
    u = lift[u][0];
    v = lift[v][0];
    assert(u == v);
    return u;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    memset(pre, 0, sizeof(pre));
    
    for (int u = 0; u < n; u++) {
        int v; cin >> v;
        v--;
        nxt[u] = v;
        pre[v].push_back(u);
    }

    for (int u = 0; u < n; u++) {
        dfsCycle(u);
    }

    for (int u = 0; u < n; u++) if (isCycle[u]) {
        int v = nxt[u];
        while (!isCycle[v]) {
            isCycle[v] = 1;
            v = nxt[v];
        }
    }

    for (int u = 0; u < n; u++) {
        if (isCycle[u]) {
            dfsDepth(u, 0, u);
            lift[u][0] = u;
        } else {
            lift[u][0] = nxt[u];
        }
    }

    for (int k = 1; k < maxk; k++) {
        for (int u = 0; u < n; u++) {
            lift[u][k] = lift[lift[u][k-1]][k-1];
        }
    }

    for (int u = 0; u < n; u++) {
        if (!isCycle[u] || depthCycle[u]) continue;
        int v = u;
        int d = 1;
        while (nxt[v] != u) {
            v = nxt[v];
            cycleRoot[v] = u;
            depthCycle[v] = d++; 
        }
        szCycle[u] = d;
        cycleRoot[u] = u;
    }

    // for (int i = 0; i < n; i++) {
    //     if (isCycle[i]) {
    //         cout << i + 1 << ": " << cycleRoot[i] + 1 << " " << depthCycle[i] << " " << szCycle[i] << "\n";
    //     }
    // }


    while (q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (whichRoot[u] != whichRoot[v]) {
            int res = depth[u];
            if (isCycle[v] && cycleRoot[v] == cycleRoot[whichRoot[u]]) {
                res += (depthCycle[v] - depthCycle[whichRoot[u]] + szCycle[cycleRoot[v]]) % szCycle[cycleRoot[v]];
                cout << res << "\n";
            } else cout << "-1\n";
        } else {
            int lc = lca(u, v);
            if (lc == v) cout << depth[u] - depth[v] << "\n"; 
            else cout << "-1\n";
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i + 1 << " " << depth[i] << "\n";
    // }

    


}
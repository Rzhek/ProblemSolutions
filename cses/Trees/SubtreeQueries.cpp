#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5+5;
int n, q, timer = 0, in[maxn], out[maxn], nums[maxn];
vector<int> adj[maxn];
ll fen[maxn];

inline void add(int p, int val) {
    for (p++; p < maxn; p += p&-p) fen[p] += val;
}
inline ll get(int p) {
    p++;
    ll res = 0;
    for (; p; p -= p&-p) res += fen[p];
    return res;
}
inline ll get(int a, int b) { // [a, b]
    return get(b) - get(a - 1);
}

void dfs(int u, int p = -1) {
    in[u] = timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        timer++;
        dfs(v, u);
    }
    out[u] = timer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);
    for (int i = 0; i < n; i++) {
        add(in[i], nums[i]);
    }

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u, v; cin >> u >> v;
            u--;
            add(in[u], v - get(in[u], in[u]));
        } else {
            int u; cin >> u;
            u--;
            cout << get(in[u], out[u]) << " ";
        }
    }
    cout << "\n";
}
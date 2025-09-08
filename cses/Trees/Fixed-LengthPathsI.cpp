#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 2e5+5;
int n, k, removed[maxn], sz[maxn];
vector<int> adj[maxn];
ll res = 0;

void add_val(vector<int> &vec, int i, int val) {
    while (vec.size() - 1 < i) vec.push_back(0);
    vec[i] += val;
}

int dfs(int u, int p = -1) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        sz[u] += dfs(v, u);;
    }
    return sz[u];
}

int find_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        if (sz[v] * 2 > total) return find_centroid(v, u, total);
    }
    return u;
}

void count(int u, int p, int depth, vector<int> &data) {
    if (depth == k) return;
    add_val(data, depth, 1);
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        count(v, u, depth + 1, data);
    }

}

void decomp(int u) {
    int centroid = find_centroid(u, -1, dfs(u));
    vector<int> cur = {1};

    for (int v : adj[centroid]) {
        if (removed[v]) continue;
        vector<int> nxt = {0};
        count(v, centroid, 1, nxt);
        for (int i = 1; i < nxt.size(); i++) {
            if (cur.size() - 1 < k - i - 1) continue;
            res += (ll)nxt[i] * cur[k-i-1];
        }
        for (int i = 1; i < nxt.size(); i++) add_val(cur, i, nxt[i]);
    }

    removed[centroid] = 1;
    for (int v : adj[centroid]) {
        if (removed[v]) continue;
        decomp(v);
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    k++;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    decomp(0);
    cout << res << "\n";

}
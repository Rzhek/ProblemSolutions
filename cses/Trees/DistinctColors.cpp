#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int n, color[maxn], ans[maxn];
vector<int> adj[maxn];

void solve(int u, int p, set<int> &cur_set) {
    cur_set.insert(color[u]);

    for (int v : adj[u]) {
        if (v == p) continue;
        set<int> new_set;
        solve(v, u, new_set);
        if (cur_set.size() < new_set.size()) swap(cur_set, new_set);

        for (int i : new_set) cur_set.insert(i);
    }

    ans[u] = cur_set.size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> color[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> cur_set;
    solve(0, -1, cur_set);

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}
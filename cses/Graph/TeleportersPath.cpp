#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

using vi = vector<int>;
using pii = pair<int, int>;

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src = 0) {
    int n = sz(gr);
    vi D(n), its(n), eu(nedges), ret, s = {src};
    D[src]++; // to allow Euler paths , not jus t cyc les
    while (!s.empty()) {
        int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
        if (it == end) {
            ret.push_back(x), s.pop_back();
            continue;
        }
        tie(y, e) = gr[x][it++];
        if (!eu[e]) {
            D[x]--, D[y]++;
            eu[e] = 1, s.push_back(y);
        }
    }
    for (int x : D)
        if (x < 0 || sz(ret) != nedges + 1) return {};
    return {ret.rbegin(), ret.rend()};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v, i);
    }
    vi walk = eulerWalk(adj, m);

    if (walk.size() && walk.back() == n - 1) {
        for (int x : walk) cout << x + 1 << " ";
    } else {
        cout << "IMPOSSIBLE";
    }
    cout << "\n";

}
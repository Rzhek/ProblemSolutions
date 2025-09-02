#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

struct DSU {
    vi par, sz;
    int n;
    int numComponents, largest;
    
    DSU (int n) : n(n), numComponents(n), largest(1) {
        par = vi(n);
        sz = vi(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        int p1 = find(u), p2 = find(v);
        if (p1 == p2) return false;
        
        if (sz[p1] > sz[p2]) swap(p1, p2);
        par[p1] = p2;
        sz[p2] += sz[p1];
        numComponents--;
        largest = max(largest, sz[p2]);
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        dsu.join(u, v);
        cout << dsu.numComponents << " " << dsu.largest << "\n";
    }
}
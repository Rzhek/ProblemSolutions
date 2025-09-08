#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vector<array<int, 2>> dirs = {
    {1, 0}, {-1, 0}, {0, -1}, {0, 1}
};

struct DSU {
    int n;
    vi par, sz;

    DSU(int n): n(n) {
        par = vi(n);
        sz = vi(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> m >> n >> q;

    vector<vi> grid(n, vi(m));
    vector<array<int, 4>> queries(q);
    for (auto &[c1, r1, c2, r2] : queries) {
        cin >> c1 >> r1 >> c2 >> r2;
        c1--; r1--; c2--; r2--;
        for (int r = r1, c = c1; r <= r2 && c <= c2; r += (c1 == c2), c += (r1 == r2)) grid[r][c]++;
    }

    DSU dsu(n * m);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c]) continue;
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc]) continue;
                dsu.join(nr * m + nc, r * m + c);
            }
        }
    }

    set<int> pars;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (!grid[r][c]) pars.insert(dsu.find(r * m + c));
        }
    }

    int cur = pars.size();

    reverse(queries.begin(), queries.end());

    vi ans;
    ans.push_back(cur);
    ans.reserve(q+1);
    for (auto [c1, r1, c2, r2] : queries) {
        for (int r = r1, c = c1; r <= r2 && c <= c2; c += (r1 == r2), r += (c1 == c2)) {
            if (!--grid[r][c]) {
                pars.clear();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc]) continue;
                    pars.insert(dsu.find(nr * m + nc));
                }
                cur += 1 - pars.size();
                for (int i : pars) dsu.join(r * m + c, i);
            }
        }
        ans.push_back(cur);
    }

    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << "\n";
}
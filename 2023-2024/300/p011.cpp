#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using iii = tuple<int, int, int>;

const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;
vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct DSU {
    vector<int> s;
    DSU(int n): s(n, -1) {}
    int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b], s[b] = a;
        return true;
    }
    int size(int i) { return -s[find(i)]; }
    bool same(int a, int b) { return find(a) == find(b); }
};

int n, m, q;

void merge(DSU &dsu, vvi &grid, int r1, int c1, int r2, int c2) {
    if (r1 == 0 || r1 == n+1 || r2 == 0 || r2 == n+1 || c1 == 0 || c1 == m+1 || c2 == 0 || c2 == m+1) return;
    if (grid[r1][c1] || grid[r2][c2]) return;
    dsu.join(r1 * (m + 2) + c1, r2 * (m + 2) + c2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n >> q;
    DSU dsu((n + 2) * (m + 2));
    vvi grid(n + 2, vi(m + 2, 0));
    forn(i, n + 2) grid[i][0] = grid[i][m+1] = 1;
    forn(i, m + 2) grid[0][i] = grid[n+1][i] = 1;
    vector<vpi> changes(q + 1);
    forn(i, q) {
        int c1, r1, c2, r2; cin >> c1 >> r1 >> c2 >> r2;
        for (int c = c1; c <= c2; c++) {
            for (int r = r1; r <= r2; r++) {
                if (grid[r][c]) continue;
                grid[r][c] = 1;
                changes[i].emplace_back(r, c);
            }
        }
    }

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            merge(dsu, grid, r, c, r-1, c);
            merge(dsu, grid, r, c, r+1, c);
            merge(dsu, grid, r, c, r, c-1);
            merge(dsu, grid, r, c, r, c+1);
        }
    }

    set<int> regions;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            if (grid[r][c]) continue;
            regions.insert(dsu.find(r * (m + 2) + c));
        }
    }
    vi ans(q+1);
    ans[q] = regions.size();
    for (int i = q-1; i >= 0; i--) {
        set<int> parents;
        for (auto [r, c] : changes[i]) {
            for (auto [dr, dc] : dirs) {
                if (grid[r+dr][c+dc]) continue;
                parents.insert(dsu.find((r + dr) * (m + 2) + (c + dc)));
            }
        }
        int before = parents.size();
        parents.clear();
        for (auto [r, c] : changes[i]) {
            grid[r][c] = 0;
            for (auto [dr, dc] : dirs) {
                merge(dsu, grid, r, c, r + dr, c + dc);
            }
        }
        for (auto [r, c] : changes[i]) {
            parents.insert(dsu.find(r * (m + 2) + c));
        }
        int after = parents.size();
        ans[i] = ans[i+1] + (after - before);
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
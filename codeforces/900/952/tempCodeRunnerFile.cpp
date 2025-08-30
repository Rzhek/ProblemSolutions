#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
using ld = long double;
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

int n, m; 
vector<vector<char>> grid;

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

vpi dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void merge(int r, int c, DSU &dsu) {
    for (auto [dr, dc] : dirs) {
        int r1 = r + dr, c1 = c + dc;
        if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= m) continue;
        if (grid[r][c] == '#' && grid[r1][c1] == '#') dsu.join(r1 * m + c1, r * m + c);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        cin >> n >> m;
        // grid.resize(n, vector<char>(m));
        grid = vector<vector<char>>(n, vector<char>(m));
        
        forn (r, n) forn (c, m) {
            cin >> grid[r][c];
        }

        DSU dsu(n * m);
        forn (r, n) forn (c, m) merge(r, c, dsu);
        
        int res = 0;
        forn (r, n) {
            int cur = 0;
            set<int> unique;
            forn (c, m) {
                if (r > 0 && grid[r-1][c] == '#') {
                    unique.insert(dsu.find((r-1) * m + c));
                }
                if (r < n - 1 && grid[r+1][c] == '#') {
                    unique.insert(dsu.find((r+1) * m + c));
                }
                if (grid[r][c] == '#') {
                    unique.insert(dsu.find(r * m + c));
                } else cur++;
            }
            for (int i : unique) cur += dsu.size(i);
            res = max(res, cur);
        }
        forn (c, m) {
            int cur = 0;
            set<int> unique;
            forn (r, n) {
                if (c > 0 && grid[r][c-1] == '#') {
                    unique.insert(dsu.find(r * m + c-1));
                }
                if (c < m - 1 && grid[r][c+1] == '#') {
                    unique.insert(dsu.find(r * m + c+1));
                }
                if (grid[r][c] == '#') {
                    unique.insert(dsu.find(r * m + c));
                } else cur++;
            }
            // cout << c << ": " << cur << "\n";
            for (int i : unique) {
                cur += dsu.size(dsu.find(i));
                // cout << i << ": (" << i / n << " " << i % n << "): " << dsu.size(dsu.find(i)) << "\n";
            }
            // cout << c << ": " << cur << "\n";
            // for (int i : unique) cout << "(" << i / n << " " << i % n << "): " << dsu.size(i) << "\n";
            res = max(res, cur);
        }
        cout << res << '\n';

    }
    return 0;
}
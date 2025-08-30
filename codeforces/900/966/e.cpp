#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, m, k; cin >> n >> m >> k;
        vvl grid(n + 2, vl(m + 2, 0));

        priority_queue<pair<ll, pii>> grid_pq;

        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                int left = max(1, c - k + 1);
                int right = min(m, c + k - 1);
                int up = max(1, r - k + 1);
                int down = min(n, r + k - 1);
                // grid[r][c] = (right - left + 2 - k) * (down - up + 2 - k);
                grid_pq.push({(right - left + 2 - k) * (down - up + 2 - k), {r, c}});
            }
        }

        priority_queue<int> pos_pq;
        int w; cin >> w;
        forn (i, w) {
            int a; cin >> a;
            pos_pq.push(a);
        }

        while (grid_pq.size() && pos_pq.size()) {
            auto [bruh, pos] = grid_pq.top();
            grid_pq.pop();
            int h = pos_pq.top();
            pos_pq.pop();
            grid[pos.f][pos.s] = h;
        }

        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                grid[r][c] += grid[r][c-1];
            }
        }
        for (int c = 1; c <= m; c++) {
            for (int r = 1; r <= n; r++) {
                grid[r][c] += grid[r-1][c];
            }
        }

        ll res = 0;
        for (int r = k; r <= n; r++) {
            for (int c = k; c <= m; c++) {
                res += grid[r][c] - grid[r-k][c] - grid[r][c-k] + grid[r-k][c-k];
            }
        }

        cout << res << "\n";

    }
    return 0;
}
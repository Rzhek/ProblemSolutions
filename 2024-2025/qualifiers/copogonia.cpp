#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
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

int n, k, m; 

double dist(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> m;
    vector<pii> pts(n);
    forn (i, n) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y};
    }
    vector<iii> roads(k);
    forn (i, k) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        roads[i] = {a, b, c};
    }

    int res = 1e9;
    for (int subset = 1; subset < (1 << k); subset++) {
        vector<vector<double>> graph(n, vector<double>(n, inf));
        forn (i, n) {
            int j = (i + 1) % n;
            graph[i][j] = graph[j][i] = dist(pts[i].f, pts[i].s, pts[j].f, pts[j].s);
        }
        forn (i, n) graph[i][i] = 0;

        int cost = 0;
        for (int i = 0; i < k; i++) {
            if (subset & (1 << i)) {
                auto [u, v, c] = roads[i];
                graph[u][v] = graph[v][u] = dist(pts[u].f, pts[u].s, pts[v].f, pts[v].s);
                cost += c;
            }
        }

        forn (k, n) forn (i, n) forn (j, n) {
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }

        double maxi = 0;
        forn (i, n) forn (j, n) maxi = max(maxi, graph[i][j]);
        // cout << subset << " " << cost << " " << maxi << "\n";
        if (maxi <= m) res = min(res, cost);
    }

    cout << res << "\n";

    return 0;
}
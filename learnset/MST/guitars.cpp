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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;

    for (int t = 1; t <= tt; t++) {
        int n, m; cin >> n >> m;
        vector<vpi> edges(n);
        forn (i, m) {
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            edges[u].emplace_back(v, w);
            edges[v].emplace_back(u, w);
        }

        int res = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, 0);
        vi visited(n, 0);
        while (pq.size()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (visited[u]) continue;
            visited[u] = 1;
            res += w;
            for (auto [v, dw] : edges[u]) {
                if (visited[v]) continue;
                pq.emplace(dw, v);
            } 
        }

        if (accumulate(all(visited), 0) < n) res = -1;
        cout << res << "\n"; 
    }
    return 0;
}
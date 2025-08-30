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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t, d; cin >> n >> m >> t >> d;
    vi repairs(t + 1);
    repairs[t] = n - 1;
    forn(i, t) cin >> repairs[i], repairs[i]--;
    vvl mat(n, vl(n, inf));
    forn(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        ll w; cin >> w;
        mat[u][v] = mat[v][u] = w;
    }
    forn(i, n) mat[i][i] = 0;
    forn(k, n) forn(i, n) forn(j, n) mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

    vl dist(n, inf);
    priority_queue<pii, vpi, greater<pii>> pq;
    pq.emplace(0, 0);
    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (dist[u] < w) continue;
        dist[u] = w;
        for (int v : repairs) {
            if (u == v || dist[v] <= w + mat[u][v] || mat[u][v] > d) continue;
            dist[v] = w + mat[u][v];
            pq.emplace(w + mat[u][v], v);
        }
    }

    if (dist[n-1] < inf) cout << dist[n-1] << "\n";
    else cout << "stuck\n";
    return 0;
}
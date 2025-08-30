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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<vpl> edges(n);
    vector<priority_queue<ll>> best(n);
    forn (i, m) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u].emplace_back(v, w);
    }
    priority_queue<pll, vpl, greater<pll>> pq;

    pq.emplace(0, 0);
    best[0].push(0);

    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (w > best[u].top()) continue;
        for (auto [v, dw] : edges[u]) {
            if (best[v].size() < k) {
                best[v].push(w + dw);
                pq.emplace(w + dw, v);
            } else if (w + dw < best[v].top()) {
                best[v].pop();
                best[v].push(w + dw);
                pq.emplace(w + dw, v);
            }
        }
    }

    vl res;
    while (best[n-1].size()) {
        res.pb(best[n-1].top());
        best[n-1].pop();
    }
    reverse(all(res));
    printArr(res);    
    return 0;
}
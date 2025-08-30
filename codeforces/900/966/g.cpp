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

int n, m, t0, t1, t2;
const int maxn = 2e5+10;
vector<iii> edges[maxn];
ll dist[maxn];

int canBus(ll start, ll end) {
    if (start <= t1 && t1 < end) return 0;
    if (start < t2 && t2 <= end) return 0;
    if (t1 <= start && end <= t2) return 0;
    return 1;
}

int solve(int start) {
    forn (i, n) dist[i] = inf;
    priority_queue<pll, vpl, greater<pll>> pq;
    pq.emplace(start, 0);
    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (dist[u] < w || w > t0) continue;
        dist[u] = w;
        if (u == n - 1) break;

        for (auto [v, bus, foot] : edges[u]) {
            if (!canBus(w, w + bus)) {
                ll arriveTime = min(w + foot, (ll)t2 + bus);
                if (dist[v] <= arriveTime) continue;
                dist[v] = arriveTime;
                pq.emplace(arriveTime, v);
            } else {
                if (dist[v] <= w + bus) continue;
                dist[v] = w + bus;
                pq.emplace(w + bus, v);
            }
        }
    }

    return dist[n-1] <= t0; 

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        cin >> n >> m;
        cin >> t0 >> t1 >> t2;

        forn (i, m) {
            int u, v, l1, l2; cin >> u >> v >> l1 >> l2;
            u--; v--;
            edges[u].emplace_back(v, l1, l2);
            edges[v].emplace_back(u, l1, l2);
        }

        int lo = 0, hi = t0;
        int res = -1;
        while (lo <= hi) {
            int m = (lo + hi) >> 1;
            if (solve(m)) {
                lo = m + 1;
                res = m;
            } else {
                hi = m - 1;
            }
        }
        cout << res << "\n";

        forn (i, n) edges[i].clear();
    }
    return 0;
}
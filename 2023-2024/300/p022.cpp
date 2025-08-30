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

int n, m, k;
vector<vector<ll>> dist;
vector<iii> orders;
vvl late, len;

int check(ll maxDelay) {
    vl memo(k, inf);
    for (int r = 0; r < k; r++) {
        ll mn = inf;
        for (int l = 0; l <= r; l++) {
            ll start = max(l == 0 ? 0LL : memo[l-1], (ll)get<1>(orders[r]));
            if (start == inf) break;
            if (late[l][r] + start <= maxDelay) {
                mn = min(mn, len[l][r] + start);
            }
        }
        memo[r] = mn;
        if (mn == inf) {
            for (int i = r; i < k; i++) {
                memo[i] = inf;
            }
            break;
        }
    }
    return memo.back() != inf;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    dist.resize(n, vector<ll>(n, inf));
    vector<vpi> edges(n);
    forn (i, m) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }
    
    forn (i, n) dist[i][i] = 0;
    forn (i, n) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(0, i);
        while (pq.size()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (w > dist[i][u]) continue;
            for (auto [v, dw] : edges[u]) {
                if (w + dw >= dist[i][v]) continue;
                dist[i][v] = w + dw;
                pq.emplace(w + dw, v);
            }
        }
    }

    cin >> k;
    late.resize(k, vl(k, inf));
    len.resize(k, vl(k, inf));
    forn (i, k) {
        int s, u, t; cin >> s >> u >> t;
        u--;
        orders.emplace_back(s, t, u);
    }
    
    rep(i, 0, k) {
        ll now = 0, worst = -inf;
        int at = 0;
        rep(j, i, k) {
            now += dist[at][get<2>(orders[j])];
            at = get<2>(orders[j]);
            worst = max(worst, now - get<0>(orders[j]));
            late[i][j] = worst;
            len[i][j] = now + dist[at][0];
        }
    }

    ll lo = 0, hi = 1e15;
    ll res = 1e9;
    while (lo <= hi) {
        ll m = (lo + hi) / 2;
        if (check(m)) {
            res = m;
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }

    cout << res << "\n";
    return 0;
}
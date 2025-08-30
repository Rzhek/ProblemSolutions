#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#include <bits/extc++.h>
const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pi;
    vector<pii> par;
    MCMF(int N):
        N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap), seen(N), dist(N), pi(N), par(N) {}
    void addEdge(int from, int to, ll cap, ll cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }
    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0;
        ll di;
        __gnu_pbds::priority_queue<pair<ll, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});
        auto relax = [&](int i, ll cap, ll cost, int dir) {
            ll val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };
        while (!q.empty()) {
            s = q.top().second;
            q.pop();
            seen[s] = 1;
            di = dist[s] + pi[s];
            for (int i : ed[s])
                if (!seen[i])
                    relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            for (int i : red[s])
                if (!seen[i]) relax(i, flow[i][s], -cost[i][s], 0);
        }
        rep(i, 0, N) pi[i] = min(pi[i] + dist[i], INF);
    }
    pair<ll, ll> maxflow(int s, int t) {
        ll totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            ll fl = INF;
            for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        rep(i, 0, N) rep(j, 0, N) totcost += cost[i][j] * flow[i][j];
        return {totflow, totcost};
    }
    // If some costs can be negative , call this before maxflow :
    void setpi(int s) { // (otherwise , leave this out)
        fill(all(pi), INF);
        pi[s] = 0;
        int it = N, ch = 1;
        ll v;
        while (ch-- && it--)
            rep(i, 0, N) if (pi[i] != INF) for (int to : ed[i]) if (cap[i][to]) if ((v = pi[i] + cost[i][to]) < pi[to])
                pi[to] = v,
                ch = 1;
        assert(it >= 0); // negative cost cycle
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    MCMF mcmf(2 + 2 * n + n * n);
    int s = 2 * n + n * n, t = s + 1;
    int totR = 0, totC = 0;

    // for rows
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) mcmf.addEdge(s, i, x, 0);
        totR += x;
    }
    // for cols
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) mcmf.addEdge(n + i, t, x, 0);
        totC += x;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int x; cin >> x;
            mcmf.addEdge(r, n + c, 1, -x);
        }
    }

    mcmf.setpi(s);
    auto [flow, cost] = mcmf.maxflow(s, t);
    if (totR != totC || totC != flow) {
        cout << "-1\n";
        return 0;
    }
    cout << -cost << "\n";

    vector<string> res(n, string(n, '.'));

    for (int r = 0; r < n; r++) {
        for (int c = n; c < 2 * n; c++) {
            if (mcmf.flow[r][c] <= 0) continue;
            res[r][c-n] = 'X';
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << res[r][c];
        }
        cout << "\n";
    }

}
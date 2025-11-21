#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<pair<int, int>>;

struct mcmf {
    const ll inf = LLONG_MAX >> 2;
    struct edge {
        int v;
        ll cap, flow, cost;
    };
    int n;
    vector<edge> edges;
    vvi adj; vii par; vi in_q;
    vector<ll> dist, pi;
    mcmf(int n): n(n), adj(n), dist(n), pi(n), par(n), in_q(n) {}
    void add_edge(int u, int v, ll cap, ll cost) {
        int idx = sz(edges);
        edges.push_back({v, cap, 0, cost});
        edges.push_back({u, cap, cap, -cost});
        adj[u].push_back(idx);
        adj[v].push_back(idx ^ 1);
    }
    bool find_path(int s, int t) {
        fill(all(dist), inf);
        fill(all(in_q), 0);
        queue<int> q; q.push(s);
        dist[s] = 0, in_q[s] = 1;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            in_q[cur] = 0;
            for(int idx: adj[cur]) {
                auto [nxt, cap, fl, wt] = edges[idx];
                ll nxtD = dist[cur] + wt;
                if(fl >= cap || nxtD >= dist[nxt]) continue;
                dist[nxt] = nxtD;
                par[nxt] = {cur, idx};
                if(in_q[nxt]) continue;
                q.push(nxt); in_q[nxt] = 1;
            }
        }
        return dist[t] < inf;
    }
    pair<ll, ll> calc(int s, int t) {
        ll flow = 0, cost = 0;
        while(find_path(s, t)) {
            rep(i, 0, n) pi[i] = min(pi[i] + dist[i], inf);
            ll f = inf;
            for(int i, u, v = t; tie(u, i) = par[v], v != s; v = u)
            f = min(f, edges[i].cap - edges[i].flow);
            flow += f;
            for(int i, u, v = t; tie(u, i) = par[v], v != s; v = u)
            edges[i].flow += f, edges[i^1].flow -= f;
        }
        rep(i, 0, sz(edges) >> 1)
        cost += edges[i<<1].cost * edges[i<<1].flow;
        return {flow, cost};
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    mcmf guy(n+1);
    guy.add_edge(0, 1, k, 0);
    while (m--) {
        int u, v, r, c; cin >> u >> v >> r >> c;
        u; v;
        guy.add_edge(u, v, r, c);
    }

    auto [flow, cost] = guy.calc(0, n);
    if (flow < k) cost = -1;
    cout << cost << "\n";

}
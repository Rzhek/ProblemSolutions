#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using vi = vector<int>;
using ll = long long;




template<bool VALS_EDGES> struct HLD {
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, depth, rt, pos;
    Node* tree;
    HLD(vector<vi> adj_):
        N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N), rt(N), pos(N), tree(new Node(0, N)) {
            dfsSz(0);
            dfsHld(0);
    }
    void dfsSz(int v) {
        if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
        for (int& u : adj[v]) {
            par[u] = v, depth[u] = depth[v] + 1;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }
    void dfsHld(int v) {
        pos[v] = tim++;
        for (int u : adj[v]) {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }
    template<class B> void process(int u, int v, B op) {
        for (; rt[u] != rt[v]; v = par[rt[v]]) {
            if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }
    void modifyPath(int u, int v, int val) {
        process(u, v, [&](int l, int r) { tree->add(l, r, val); });
    }
    int queryPath(int u, int v) {
        int res = -1e9;
        process(u, v, [&](int l, int r) {
            res = max(res, tree->query(l, r));
        });
        return res;
    }
    int querySubtree(int v) {
        return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
    }
};

using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pii>> edges(n);
    map<pii, int> weights;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
        weights[{u, v}] = weights[{v, u}] = w;
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    vi visited(n);
    pq.push({0, 0, -1});
    ll res = 0;
    vector<vi> treeEdges(n);
    while (pq.size()) {
        auto [w, u, par] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        if (par != -1) {
            treeEdges[u].push_back(par);
            treeEdges[par].push_back(u);
        }
        res += w;
        for (auto [v, dw] : edges[u]) {
            if (visited[v]) continue;
            pq.push({dw, v, u});
        }
    }


    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (auto x : treeEdges[i]) cout << x << " ";
    //     cout << "\n";
    // }

    HLD<true> hld(treeEdges);

    for (int u = 0; u < n; u++) {
        for (auto v : treeEdges[u]) {
            if (u <= v) continue;
            hld.modifyPath(u, v, weights[{u, v}]);
        }
    }

    // cout << hld.queryPath(1, 2) << "\n";

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        assert(weights.count({a, b}));
        cout << res + weights[{a, b}] - hld.queryPath(a, b) << "\n";
    }



}

// #define sz(x) (int)(x).size()
// #define rep(i,a,b) for (int i = a; i < (b); i++)

// vector<vi> treeJump(vi& P) {
//     int on = 1, d = 1;
//     while(on < sz(P)) on *= 2, d++;
//     vector<vi> jmp(d, P);
//     rep(i,1,d) rep(j,0,sz(P))
//         jmp[i][j] = jmp[i-1][jmp[i-1][j]];
//     return jmp;
// }

// int jmp(vector<vi> &tbl, int nod, int steps) {
//     rep(i,0,sz(tbl))
//         if(steps&(1<<i)) nod = tbl[i][nod];
//     return nod;
// }

// int lca(vector<vi>& tbl, vi&depth, int a, int b) {
//     if (depth[a] < depth[b]) swap(a, b);
//     a = jmp(tbl, a, depth[a] - depth[b]);
//     if (a == b) return a;
//     for (int i = sz(tbl); i--;) {
//         int c = tbl[i][a], d = tbl[i][b];
//         if (c != d) a = c, b = d;
//     }
//     return tbl[0][a];
// }

// int main() {
//     int n, r, a, b, c; cin >> n >> r;

//     vector adj(n, vector<pair<int, int>>());
//     map<pair<int, int>, ll> mp;

//     while (r--) {
//         cin >> a >> b >> c;
//         a--; b--;
//         adj[a].emplace_back(b, c);
//         adj[b].emplace_back(a, c);
//         mp[{a, b}] = c;
//     }

//     priority_queue<tuple<ll, int, int>> pq;
//     pq.push({0, 0, 0});

//     ll total_cost = 0;

//     vector<int> parent(n, -1);
//     vector<int> depth(n, -1);
//     vector<ll> cost(n, 0);

//     while (!pq.empty()) {
//         auto [c, b, a] = pq.top();
//         pq.pop();

//         if (parent[b] != -1) continue;

//         parent[b] = a;
//         depth[b] = 1 + depth[a];
//         cost[b] = c + cost[a];

//         total_cost += c;

//         for (auto [a, c] : adj[b]) {
//             pq.push({-c, a, b});
//         }
//     }

//     total_cost *= -1;

//     vector<vi> tbl = treeJump(parent);

//     int q; cin >> q;

//     while (q--) {
//         cin >> a >> b;
//         a--; b--;

//         int l = lca(tbl, depth, a, b);

//         cout << total_cost << ' ' << cost[a] << ' ' << cost[b] << ' ' << cost[l] << mp[{a, b}] << '\n';

//         // cout << total_cost - cost[a] - cost[b] + 2 * cost[l]  + mp[{a, b}] << '\n';

//     }


// }
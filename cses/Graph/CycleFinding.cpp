#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)

using ll = long long;

const ll inf = LLONG_MAX;
struct Ed { int a, b, w, s() { return a < b ? a : -a; }};
struct Node { ll dist = inf; int prev = -1; };

void bellmanFord(vector<Node>& nodes, vector<Ed>& eds, int s) {
    nodes[s].dist = 0;
    sort(all(eds), [](Ed a, Ed b) { return a.s() < b.s(); });

    int lim = sz(nodes) / 2 + 2;
    rep(i, 0, lim) for (Ed ed : eds) {
        Node cur = nodes[ed.a], &dest = nodes[ed.b];
        if (abs(cur.dist) == inf) continue;
        ll d = cur.dist + ed.w;
        if (d < dest.dist) {
            dest.prev = ed.a;
            dest.dist = (i < lim-1 ? d : -inf);
        }
    }
    rep(i, 0, lim) for (Ed e : eds) {
        if (nodes[e.a].dist == -inf)
            nodes[e.b].dist = -inf;
    } 
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<Node> nodes(n + 1);
    vector<Ed> eds; eds.reserve(n + m);

    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        eds.push_back({u, v, w});
    }
    for (int i = 0; i < n; i++) eds.push_back({n, i, 0});


    bellmanFord(nodes, eds, n);

    // for (int i = 0; i <= n; i++) {
    //     auto node = nodes[i];
    //     cout << i + 1 << ": " << node.dist << " " << node.prev + 1 << "\n";
    // }

    for (int i = 0; i < n; i++) {
        vector<int> global_vis(n+1);
        if (!global_vis[i] && nodes[i].dist == -inf && nodes[i].prev != n) {
            vector<int> res = {i};
            vector<int> vis(n + 1);
            int cur = i;
            while (cur != -1 && !vis[cur]) {
                // cout << cur << "\n";
                res.push_back(cur);
                vis[cur] = 1;
                global_vis[cur] = 1;
                cur = nodes[cur].prev;
            }
            if (cur == -1) continue;
            cout << "YES\n";
            res.push_back(cur);
            reverse(res.begin(), res.end());
            for (int j = 0; j < res.size(); j++) {
                cout << res[j] + 1 << " ";
                if (j && res[j] == res[0]) break;
            }
            cout << "\n";
            return 0;
        }
    }

    cout << "NO\n";
}
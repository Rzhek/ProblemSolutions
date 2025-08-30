#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef tuple<ll, ll, ll> ord;

vector<ord> orders;
unordered_map<tuple<ll, ll>, ll> memo;
int n, m, k; 

tuple<ll, ll> deliver(int i, int j, ll time, vll edges) {
    ll waitTime = 0;
    int cur = 0;
    for (int next = i; next <= j; next++) {
        auto [s, u, t] = orders[next];
        time += edges[cur][u];
        waitTime = max(waitTime, time - s);
        cur = u;
    }
    time += edges[cur][0];
    return {waitTime, time};
}

ll dp(int i, int j, ll time, vll edges) {
    if (j >= k) {
        auto [res, time1] = deliver(i, j - 1, time, edges);
        return res;
    }

    // take
    auto [s, u, t] = orders[j];
    time = max(time, t);

    // deliver
    auto [res1, time1] = deliver(i, j, time, edges);
    res1 = max(res1, dp(j + 1, j + 1, time1, edges));

    // Wait
    ll res2 = dp(i, j + 1, time, edges);

    ll res = min(res1, res2);
    return res;
}

int main() {
    cin >> n >> m;
    ll inf = 1e10;
    vll edges(n, vl(n, inf));
    for (int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u][v] = w;
        edges[v][u] = w;
    }

    for (int i = 0; i < n; i++) edges[i][i] = 0;

    cin >> k;
    for (int i = 0; i < k; i++) {
        ll s, u, t; cin >> s >> u >> t;
        u--;;
        orders.push_back({s, u, t});
    }

    for (int start = 0; start < n; start++) {
        priority_queue<pair<ll, int>> pq;
        for (int v = 0; v < n; v++) {
            if (edges[start][v] != inf) {
                pq.push({edges[start][v], v});
            }
        }
        while (!pq.empty()) {
            ll w1 = pq.top().first; int u = pq.top().second;
            pq.pop();
            for (int v = 0; v < n; v++) {
                ll w2 = edges[u][v];
                if (w2 != inf && w1 + w2 < edges[start][v]) {
                    edges[start][v] = edges[v][start] = w1 + w2;
                    pq.push({w1 + w2, v});
                }
            }
        }
    }

    cout << dp(0, 0, 0, edges) << endl;

    return 0;
}
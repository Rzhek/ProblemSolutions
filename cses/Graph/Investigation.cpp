#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;


const int maxn = 1e5+5, MOD = 1e9+7;
const ll inf = 1e18;
int n, m, ways[maxn], minnum[maxn], maxnum[maxn];
ll dist[maxn];
vector<pli> adj[maxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        dist[i] = inf;
        minnum[i] = 1e9;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        adj[u].emplace_back(v, w);
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;
    ways[0] = 1;
    minnum[0] = maxnum[0] = 0;

    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (dist[u] < w) continue;
        dist[u] = w;
        
        for (auto [v, dw] : adj[u]) {
            if (w + dw < dist[v]) {
                dist[v] = w + dw;
                ways[v] = ways[u];
                minnum[v] = minnum[u] + 1;
                maxnum[v] = maxnum[u] + 1;
                pq.emplace(w + dw, v);
            } else if (w + dw == dist[v]) {
                dist[v] = w + dw;
                ways[v] += ways[u];
                ways[v] %= MOD;
                minnum[v] = min(minnum[v], minnum[u] + 1);
                maxnum[v] = max(maxnum[v], maxnum[u] + 1);

            }
        }
    }

    cout << dist[n-1] << " " << ways[n - 1] << " " << minnum[n - 1] << " " << maxnum[n - 1] << "\n";
}
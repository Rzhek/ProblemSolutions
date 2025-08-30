#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>>edges(n, vector<ll>(n, inf));
    for (int i = 0; i < m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        u--; v--;
        edges[v][u] = edges[u][v] = min(edges[u][v], w);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (edges[i][k] == inf || edges[k][j] == inf) continue;
                edges[j][i] = edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (a == b) {
            cout << "0\n";
            continue;
        }
        cout << (edges[a-1][b-1] < inf ? edges[a-1][b-1] : -1) << '\n';
    }

    return 0;
}
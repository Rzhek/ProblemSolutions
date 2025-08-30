#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5, maxk = 18;
int n, q, height[maxn], lift[maxk][maxn];

int dfs(int u) {
    if (u <= 1) return 0;
    if (height[u] != 0) return height[u];
    return height[u] = 1 + dfs(lift[0][u]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> lift[0][i];
    }
    for (int j = 1; j < 18; j++) {
        for (int i = 1; i <= n; i++) {
            lift[j][i] = lift[j-1][lift[j-1][i]];
        }
    }

    for (int i = 1; i <= n; i++) {
        height[i] = dfs(i);
    }

    while (q--) {
        int u, v; cin >> u >> v;
        // u = lift[0][u], v = lift[0][v]; // ? maybe i need this
        if (height[u] < height[v]) swap(u, v);

        int diff = height[u] - height[v];

        for (int i = 0; i < maxk; i++) {
            if (diff & (1 << i)) {
                u = lift[i][u];
            }
        }

        if (u == v) {
            cout << u << "\n";
            continue;
        }
        
        for (int i = maxk - 1; i >= 0; --i) {
            if (lift[i][u] != lift[i][v]) {
                u = lift[i][u];
                v = lift[i][v];
            } 
        }

        cout << lift[0][u] << "\n";

        
    }
}
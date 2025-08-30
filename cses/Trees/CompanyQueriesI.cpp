#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5, maxk = 18;
int n, q, lift[maxk][maxn];

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

    while (q--) {
        int u, k; cin >> u >> k;
        for (int i = 0; i < maxk; i++) {
            if (k & (1 << i)) {
                u = lift[i][u];
            }
        }
        if (!u) u = -1;
        cout << u << "\n";

        
    }
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5, maxh = 30;
int lift[maxh][maxn], n, q;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> lift[0][i];
        lift[0][i]--;
    }

    for (int i = 1; i < maxh; i++) {
        for (int u = 0; u < n; u++) {
            lift[i][u] = lift[i-1][lift[i-1][u]];
        }
    }

    while (q--) {
        int u, k; cin >> u >> k;
        u--;
        for (int i = 0; i < maxh; i++) {
            if (k & (1 << i)) u = lift[i][u];
        }
        cout << u + 1 << "\n";
    }


}
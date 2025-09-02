#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int test = 1;
    while (n != 0 && k != 0) {
        map<string, int> ind;
        vector<vector<int>> edges(n, vector<int>(n, 1e9));
        while (k--) {
            string a, b; cin >> a >> b;
            int i = ind.count(a) ? ind[a] : (ind[a] = ind.size());
            int j = ind.count(b) ? ind[b] : (ind[b] = ind.size());
            edges[j][i] = edges[i][j] = 1;
        }

        for (int i = 0; i < n; i++) edges[i][i] = 0;
        for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, *max_element(edges[i].begin(), edges[i].end()));

        cout << "Network " << test++ << ": ";
        if (res >= 1e8) cout << "DISCONNECTED\n";
        else cout << res << "\n";
        cout << "\n";
        cin >> n >> k;
    }


    return 0;
}
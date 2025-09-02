#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vvi graph(n, vi(n));
    forn (i, n) forn (j, n) cin >> graph[i][j];

    forn (k, n) forn (i, n) forn (j, n) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    int q; cin >> q;
    while (q--) {
        int a, b, w; cin >> a >> b >> w;
        w -= 134;
        int res = 0;
        for (int i = 1; i < n; i += 2) res += graph[a][i] + graph[i][b] <= w;
        cout << res << "\n";
    }

    return 0;
}
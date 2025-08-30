#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

#define rep(i, a, b) for (int i = a; i < b; ++i)

int bfs(int i, vii &edges, vi &colors) {
    colors[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int u = q.front();
        int col = colors[u];
        q.pop();
        for (int v : edges[u]) {
            if (colors[v] == col) return 0;
            if (colors[v] != 0) continue;
            colors[v] = (col == 1) ? 2 : 1;
            q.push(v);
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vii edges(n);
    vi colors(n, 0);
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    rep(i, 0, n) {
        if (colors[i]) continue;
        int res = bfs(i, edges, colors);
        if (!res) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (auto x : colors) cout << x << " "; cout << '\n';
    return 0;
}
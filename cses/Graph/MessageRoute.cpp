#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using pi = pair<int, int>;

#define rep(i, a, b) for (int i = a; i < b; ++i)
int n;
vii edges;
vi visited;

int bfs() {
    queue<pi> q;
    q.emplace(1, 0);
    visited[0] = -2;
    while (!q.empty()) {
        auto [w, u] = q.front();
        q.pop();
        for (int v : edges[u]) {
            if (visited[v] == -1) {
                visited[v] = u;
                if (v == n - 1) return w + 1;
                q.emplace(w + 1, v);
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m; cin >> n >> m;
    edges.resize(n);
    visited.resize(n, -1);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    int res = bfs();
    if (!res) {
        cout << "IMPOSSIBLE\n";
        return 0; 
    }

    cout << res << '\n';
    vi path = {n-1};
    while (1) {
        if (visited[path.back()] == -2) break; 
        path.push_back(visited[path.back()]);
    }
    reverse(path.begin(), path.end());
    for (auto x : path) cout << x + 1 << " ";
    cout << '\n';


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

#define rep(i, a, b) for (int i = a; i < b; ++i)

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vii edges(n);
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    vi roadsToBuilt;
    vi visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        roadsToBuilt.push_back(i);
        queue<int> q;
        visited[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : edges[u]) {
                if (visited[v]) continue;
                q.push(v);
                visited[v] = 1;
            }
        }
    }

    cout << roadsToBuilt.size() - 1 << '\n';
    for (int i = 1; i < roadsToBuilt.size(); i++) {
        cout << roadsToBuilt[i-1] + 1 << " " << roadsToBuilt[i] + 1 << '\n';
    }

    return 0;
}
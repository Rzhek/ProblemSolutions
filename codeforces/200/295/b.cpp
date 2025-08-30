#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
using pi = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> visited(max(m, n) * 2, 0);
    queue<pi> q;
    q.push({n, 0});
    visited[n] = 1;
    while (!q.empty()) {
        auto [u, step] = q.front();
        q.pop();
        if (u == m) {
            cout << step << '\n';
            break;
        }
        int v1 = u * 2, v2 = u - 1;
        if (v1 < visited.size() && !visited[v1]) {
            visited[v1] = 1;
            q.push({v1, step + 1});
        } 
        if (v2 > 0 && !visited[v2]) {
            visited[v2] = 1;
            q.push({v2, step + 1});
        }
    }



    return 0;
}
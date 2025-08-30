#include <bits/stdc++.h>
using namespace std;

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<int> numEdges(n, 0);
    int before = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            before == grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        vector<int> visited(n, 0);
        visited[i] = 1;
        while (!q.empty()) {
            int u = q.front();
            // cout << u << '\n';
            q.pop();
            for (int v = 0; v < n; v++) {
                if (visited[v] || grid[u][v] == 0) continue;
                q.push(v);
                visited[v] = 1;
                if (grid[i][v] == 0) res++;
                grid[i][v] = 1;
            }
        }
    }
    cout << res << '\n';
}
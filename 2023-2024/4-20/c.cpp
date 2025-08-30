#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int val; cin >> val;
        string str; cin >> str;
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                grid[str[u] - 'A'][str[v] - 'A'] += val;
                grid[str[v] - 'A'][str[u] - 'A'] -= val;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (char)('A' + i) << ": ";
        queue<int> q;
        q.push(i);
        int visited = 0;
        visited |= (1 << i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
                if (u == v || (visited & (1 << v)) || grid[u][v] <= 0) continue;
                visited |= (1 << v);
                q.push(v);
            }
        }
        if (__builtin_popcountll(visited) == n) {
            cout << "can win" << '\n';
        } else {
            cout << "can't win\n";
        }
    }

    return 0;
}
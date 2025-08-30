#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define f first
#define s second
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; 
    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    pii start;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') start = {i, j};
        }
    }

    queue<pii> q;
    q.emplace(start.f, start.s);
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<pii> order;
    visited[start.f][start.s] = 1;
    order.emplace_back(start.f, start.s);
    vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        for (auto [dr, dc] : dirs) {
            int r = i + dr, c = j + dc;
            if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '#' ||visited[r][c]) continue;
            q.push({r, c});
            visited[r][c] = 1;
            order.push_back({r, c});
        }
    }

    for (int i = 0; i < k; i++) {
        auto [r, c] = order.back();
        order.pop_back();
        grid[r][c] = 'X';
    }

    for (auto &x : grid) {
        for (auto y : x) {
            cout << y;
        }
        cout << '\n';
    }


    return 0;
}
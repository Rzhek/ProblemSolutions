#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;

vector<pii> dirs = {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}, {-1, -2}, {-1, 2}, {1, 2}, {1, -2}};

int main() {
    int n; cin >> n;
    vector<vi> grid(n, vi(n, 1e6));
    grid[0][0] = 0;
    queue<pii> q{{{0,0}}};

    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();
        int w = grid[r][c];

        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] <= w + 1) continue;
            grid[nr][nc] = w + 1;
            q.push({nr, nc});
        }
    }

    for (auto &row : grid) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }
}
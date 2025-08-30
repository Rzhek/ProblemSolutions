#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using vc = vector<char>;
using vcc = vector<vc>;

#define rep(i, a, b) for (int i = a; i < b; ++i)

int n, m;
vector<pi> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int valid(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

void bfs(int R, int C, vcc &grid) {
    queue<pi> q;
    grid[R][C] = '#';
    q.emplace(R, C);
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (auto &[dr, dc] : dirs) {
            if (valid (r + dr, c + dc) && grid[r + dr][c + dc] == '.') {
                q.emplace(r + dr, c + dc);
                grid[r + dr][c + dc] = '#';
            }
        }
    }
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vcc grid(n, vector<char>(m));
    rep(i, 0, n) rep(j, 0, m) cin >> grid[i][j];
    int res = 0;
    rep(r, 0, n) {
        rep(c, 0, m) {
            if (grid[r][c] == '.') {
                // cout << r << " " << c << '\n';
                bfs(r, c, grid);
                res++;
            }
        }
    }

    cout << res << '\n';
}
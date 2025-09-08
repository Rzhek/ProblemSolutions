#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

const vector<pii> dirs = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int works(vvi grid, int val) {
    int n = grid.size(), m = grid.front().size();
    queue<array<int, 3>> q{{{0, 0, 0}}};
    while (q.size()) {
        auto [r, c, t] = q.front();
        q.pop();

        if (grid[r][c] - t < val) continue;
        if (r == n - 1 && c == m - 1) return 1;
        grid[r][c] = 0;

        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            q.push({nr, nc, t + 1});
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int n, m; cin >> n >> m;
        vvi grid(n, vi(m));
        for (auto &row : grid) {
            for (auto &col : row) cin >> col;
        }

        if (!works(grid, 1)) {
            cout << "impossible\n";
            continue;
        }

        int lo = 1, hi = 1e9+1;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (works(grid, m)) {
                if (lo == m) break;
                lo = m;
            }
            else {
                if (m == lo && m - 1 == hi) break;
                hi = m - 1;
            }
        }
        while (works(grid, lo + 1)) lo++;

        cout << lo << "\n";

    }
}
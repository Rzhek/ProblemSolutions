#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
vector<pii> dirs = {{1, 0}, {0, 1}};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> grid(n);
    // 0 - unvis, 1 - up, 2 - left
    vector<vector<int>> lol(n, vector<int>(n));
    for (auto &s : grid) cin >> s;
    vector<pii> cur{{0,0}}, nxt;

    while (cur.size()) {
        nxt = vector<pii>();
        sort(cur.begin(), cur.end(), [&](pii a, pii b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        });
        while (grid[cur.back().first][cur.back().second] != grid[cur[0].first][cur[0].second]) cur.pop_back();

        while (cur.size()) {
            auto [r, c] = cur.back();
            cur.pop_back();
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || lol[nr][nc]) continue;
                lol[nr][nc] = 2 - dr;
                nxt.push_back({nr, nc});
            }
        }
        cur = nxt;
    }

    string res;
    int r = n - 1, c = n - 1;
    while (r >= 0 && c >= 0) {
        res += grid[r][c];
        if (lol[r][c] == 1) r--;
        else c--;
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";


}
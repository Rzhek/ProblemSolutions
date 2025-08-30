#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m; 

int valid(int r, int c, vector<vector<char>> &grid) {
    return (0 <= r && r < n && 0 <= c && c < m && grid[r][c] != '#');
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> gridM(n, vector<int>(m, 1e9));
    vector<vector<pii>> par(n, vector<pii>(m, {-1, -1}));
    queue<tuple<int, int, int>> monsters, q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                monsters.push({i, j, 1});
                gridM[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                q.push({i, j, 0});
                par[i][j] = {-2, -2};
            }
        }
    }

    while (!monsters.empty()) {
        auto [i, j, w] = monsters.front();
        monsters.pop();
        for (auto [dr, dc] : dirs) {
            int r = i + dr, c = j + dc;
            if (!valid(r, c, grid) || gridM[r][c] <= w) continue;
            gridM[r][c] = w;
            monsters.push({r, c, w + 1});
        }
    }

    // for (auto &x : gridM) {
    //     for (auto y : x) cout << y << " ";
    //     cout << '\n';
    // }

    pii end = {-1, -1};
    auto [r, c, w] = q.front();
    if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
        cout << "YES\n0\n"; return 0;

    }
    while (!q.empty() && end.first == -1) {
        auto [i, j, w] = q.front();
        q.pop();
        for (auto [dr, dc] : dirs) {
            int r = i + dr, c = j + dc;
            if (!valid(r, c, grid) || gridM[r][c] <= (w + 1) || par[r][c].first != -1) continue;
            par[r][c] = {i, j};
            if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
                end = {r, c};
                break;
            }
            grid[r][c] = '#';
            q.push({r, c, w + 1});
        }
    }

    if (end.first == -1) {
        cout << "NO\n";
        return 0;
    }

    vector<char> res;
    while (end.first != -2) {
        pii next = par[end.first][end.second];
        if (end.second == next.second + 1) {
            res.push_back('R');
        } else if (end.second == next.second - 1) {
            res.push_back('L');
        } else if (end.first == next.first + 1) {
            res.push_back('D');
        } else if (end.first == next.first - 1) {
            res.push_back('U');
        }
        end = next;
    }
    reverse(res.begin(), res.end());
    cout << "YES\n";
    cout << res.size() << '\n';
    for (char x : res) cout << x;
    cout << '\n';
    
    return 0;
}
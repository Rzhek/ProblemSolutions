#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<pair<int, int>> dydx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (t--) {
        int rows, cols; cin >> rows >> cols;
        vector<vector<char>> grid(rows, vector<char>(cols));
        queue<pair<int, int>> q;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cin >> grid[r][c];
                if (grid[r][c] == 'P') {
                    q.push({r, c});
                    grid[r][c] = '#';
                }
            }
        }

        int res = 0;
        while (!q.empty() && !res) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (auto [dr, dc] : dydx) {
                int r = x + dr, c = y + dc;
                if (0 <= r && r < rows && 0 <= c && c < cols && grid[r][c] != '#') {
                    if (grid[r][c] == 'C') {
                        res = 1;
                        break;
                    }
                    q.push({r, c});
                    grid[r][c] = '#';
                }
            }
        }
        cout << (res ? "yes" : "no") << endl;
    }
    return 0;
}
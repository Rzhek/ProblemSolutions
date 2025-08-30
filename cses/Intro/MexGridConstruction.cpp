#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> rows(n, vector<int>(2 * n)), cols(n, vector<int>(2 * n));
    vector<vector<int>> grid(n, vector<int>(n));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int i = 0; i < 2 * n; i++) {
                if (rows[r][i] == 0 && cols[c][i] == 0) {
                    rows[r][i] = cols[c][i] = 1;
                    grid[r][c] = i;
                    break;
                }
            }
        }
    }

    for (auto &row : grid) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int n;
void solve(vector<vector<int>> &grid, vector<int> &rows, vector<int> &cols, int R, int C) {
    grid[R][C] = 0;
    rows[R]--;
    cols[C]--;

    // check the row
    for (int c = 0; c < n; c++) {
        if (cols[c] < n && grid[R][c]) solve(grid, rows, cols, R, c);
    }
    // check the col
    for (int r = 0; r < n; r++) {
        if (rows[r] < n && grid[r][C]) solve(grid, rows, cols, r, C);
    }
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;

    for (int ttt = 1; ttt <= tt; ttt++) {
        int k; cin >> n >> k;
        vector<vector<int>> grid(n, vector<int>(n, 1));
        vector<int> rows(n, n), cols(n, n);

        int res = 0;
        while (k--) {
            int r, c; cin >> r >> c;
            r--; c--;
            if (grid[r][c] == 0) res++;
            else {
                solve(grid, rows, cols, r, c);
            }
        }
        cout << "Strategy #" << ttt << ": " << res << "\n\n";
    }

}
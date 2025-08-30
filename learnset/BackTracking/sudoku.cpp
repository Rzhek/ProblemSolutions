#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii grid(9, vi(9));
vii takenRows(9, vi(9, 0));
vii takenCols(9, vi(9, 0));
vii takenSquares(9, vi(9, 0));

int getSquareIndex(int r, int c) {
    int row = r / 3;
    int col = c / 3;
    return row * 3 + col;
}

pair<int, int> getNextCell(int r, int c) {
    if (c == 8) {
        return {r + 1, 0};
    } else {
        return {r, c + 1};
    }
}

int solve(int r, int c) {
    if (r == 9) return 1;
    if (grid[r][c]) {
        pair<int, int> newPos = getNextCell(r, c);
        return solve(newPos.first, newPos.second);
    }
    for (int val = 1; val <= 9; val++) {
        if (!takenRows[r][val-1] && !takenCols[c][val-1] && !takenSquares[getSquareIndex(r, c)][val-1]) {
            pair<int, int> newPos = getNextCell(r, c);
            takenRows[r][val-1] = takenCols[c][val-1] = takenSquares[getSquareIndex(r, c)][val-1] = 1;
            grid[r][c] = val;
            int res = solve(newPos.first, newPos.second);
            if (res) return 1;
            takenRows[r][val-1] = takenCols[c][val-1] = takenSquares[getSquareIndex(r, c)][val-1] = 0;
            grid[r][c] = 0;
        }
    }
    return 0;
}

int main() {
    int t; cin >> t;
    for (int testcase = 1; testcase <= t; testcase++) {
        takenRows = vii(9, vi(9, 0));
        takenCols = vii(9, vi(9, 0));
        takenSquares = vii(9, vi(9, 0));

        int valid = 1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int val; cin >> val;
                grid[i][j] = val;
                if (val == 0) continue;
                if (!takenRows[i][val-1]) {
                    takenRows[i][val-1] = 1;
                } else {
                    valid = 0;
                }
                if (!takenCols[j][val-1]) {
                    takenCols[j][val-1] = 1;
                } else {
                    valid = 0;
                }
                if (!takenSquares[getSquareIndex(i, j)][val-1]) {
                    takenSquares[getSquareIndex(i, j)][val-1] = 1;
                } else {
                    valid = 0;
                }
            }
        }

        cout << "Test case " << testcase << ":\n"; 
        if (valid && solve(0, 0)) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << grid[i][j] << " ";
                }
                cout << '\n';
            }
        } else {
            cout << "No solution possible.\n";
        }
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int p1 = 0, p2 = 0;

int check(vector<vector<char>> &grid) {
    for (int r = 0; r < 3; r++) {
        int a = 0, b = 0;
        for (int c = 0; c < 3; c++) {
            a += grid[r][c] == 'X';
            b += grid[r][c] == 'O';
        }
        if (a == 3) return p1 = 1;
        if (b == 3) return p2 = 1;
    }
    for (int c = 0; c < 3; c++) {
        int a = 0, b = 0;
        for (int r = 0; r < 3; r++) {
            a += grid[r][c] == 'X';
            b += grid[r][c] == 'O';
        }
        if (a == 3) return p1 = 1;
        if (b == 3) return p2 = 1;
    }
    if (grid[1][1] != '_' && (
        (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || 
        (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2])
        )
    ) {
        if (grid[1][1] == 'X') p1 = 1;
        else p2 = 1;
        return 1;
    }
    return 0;
}

void fuck(vector<vector<char>> &grid, int move) {
    if (check(grid)) return;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[r][c] != '_') continue;
            grid[r][c] = move ? 'X' : 'O';
            fuck(grid, 1 - move);
            grid[r][c] = '_';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<vector<char>> grid(3, vector<char>(3));
    int move = 1;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cin >> grid[r][c];
            if (grid[r][c] != '_') move = 1 - move;
        }
    }

    fuck(grid, move);

    if (p1 && p2) cout << "Abdullah och Johan kan vinna\n";
    else if (p1) cout << "Johan kan vinna\n";
    else if (p2) cout << "Abdullah kan vinna\n";
    else cout << "ingen kan vinna\n";
}
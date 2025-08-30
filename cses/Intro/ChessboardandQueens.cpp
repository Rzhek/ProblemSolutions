#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid(8, vector<char>(8));
vector<int> vertical(8, 0), diagonal1(15, 0), diagonal2(15, 0);

int bt(int r) {
    if (r == 8) return 1;

    int res = 0;
    for (int c = 0; c < 8; c++) {
        if (grid[r][c] == '*' || vertical[c] || diagonal1[r - c + 7] || diagonal2[r + c]) continue;
        vertical[c] = 1;
        diagonal1[r - c + 7] = 1;
        diagonal2[r + c] = 1;
        res += bt(r + 1);
        vertical[c] = 0;
        diagonal1[r - c + 7] = 0;
        diagonal2[r + c] = 0;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 64; i++) cin >> grid[i / 8][i % 8];

    cout << bt(0) << '\n';

    return 0;
}
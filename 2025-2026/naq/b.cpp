#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> dirs = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

int main() {
    int n, m, N; cin >> n >> m >> N;
    queue<array<int, 3>> q;
    for (int i = 1; i <= N; i++) {
        int r, c; cin >> r >> c;
        r--; c--;
        q.push({r, c, i});
    }

    vector<vector<int>> res1(n, vector<int>(m)), res2 = res1;

    while (q.size()) {
        auto [r, c, i] = q.front();
        q.pop();

        if (!res1[r][c]) {
            res1[r][c] = i;
        } else if (!res2[r][c] && res1[r][c] != i) {
            res2[r][c] = i;
        } else continue;

        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            q.push({nr, nc, i});
        }
    }

    for (auto &row : res1) {
        for (auto col : row) cout << col << " ";
        cout << "\n";
    }
    
    for (auto &row : res2) {
        for (auto col : row) cout << col << " ";
        cout << "\n";
    }
}

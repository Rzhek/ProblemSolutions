#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int n = 8;
int grid[n][n], deg[n][n];
vector<pii> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

bool bruh(int R, int C, int wtf) {
    memset(grid, 0, sizeof(grid));
    memset(deg, 0, sizeof(deg));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                deg[r][c] += (0 <= nr && nr < n && 0 <= nc && nc < n);
            }
        }
    }

    int cnt = 1;
    while (cnt < n * n) {
        // cout << R << " " << C << "\n";
        grid[R][C] = cnt++;
        int br = -1, bc = -1;
        for (auto [dr, dc] : dirs) {
            int nr = R + dr, nc = C + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (grid[nr][nc]) continue;
            deg[nr][nc]--;
            
            if (br == -1 || (deg[nr][nc] + wtf < deg[br][bc])) {
                br = nr;
                bc = nc;
            }
        }
        R = br;
        C = bc;
    }

    grid[R][C] = cnt;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 0) return false;
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << grid[r][c] << " ";
        }
        cout << "\n";
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int C, R; cin >> C >> R; C--; R--;

    if (!bruh(R, C, 0)) bruh(R, C, 1);

}
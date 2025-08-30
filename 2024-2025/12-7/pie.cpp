#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int maxn = 1005;
int grid[maxn][maxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--) {
        int n, m, a, b; cin >> n >> m >> a >> b;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                char ch; cin >> ch;
                grid[r][c] = ch == 'x';
            }
        }
        vector<pii> pos;
        int first_r = -1, first_c = -1;
        for (int r = 0; r < a; r++) {
            for (int c = 0; c < b; c++) {
                char ch; cin >> ch;
                if (ch == '.') continue;
                if (first_r == -1) {
                    first_r = r;
                    first_c = c;
                }
                pos.emplace_back(r - first_r, c - first_c);
            }
        }
        int works = 1;
        for (int r = 0; works && r < n; r++) {
            for (int c = 0; works && c < m; c++) {
                if (!grid[r][c]) continue;
                for (auto x : pos) {
                    int nr = r + x.first, nc = c + x.second;
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0) {
                        works = 0;
                        break;
                    }
                    grid[nr][nc] = 0;
                }
            }
        }

        if (works) cout << "TAK\n";
        else cout << "NIE\n";
    }
}
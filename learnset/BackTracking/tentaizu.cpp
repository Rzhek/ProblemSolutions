#include <bits/stdc++.h>
using namespace std;

const int n = 7;
int og[n][n], grid[n][n], mines[n][n];

bool solve(int r, int c, int rem) {
    if (c == n) return solve(r + 1, 0, rem);
    if (r == n) return rem == 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        for (int r = 0; r < n; r++) {
            string s; cin >> s;
            for (int c = 0; c < n; c++) {
                if (s[c] == '.') grid[r][c] = -1;
                else grid[r][c] = s[c] - '0';
                og[r][c] = grid[r][c];
            }
        }
        solve(0, 0, 10);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cout << mines[r][c] ? '*' : og[r][c];
            }
            cout << "\n";
        }
    }
}
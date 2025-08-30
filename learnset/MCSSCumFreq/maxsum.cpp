#include <bits/stdc++.h>
using namespace std;

// #define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> grid(n + 1, vector<int>(n + 1));

        int res = -1e9;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cin >> grid[r+1][c+1];
                res = max(res, grid[r+1][c+1]);
            }
        }
        if (res <= 0) {
            cout << res << "\n";
            continue;
        }

        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= n; c++) {
                grid[r][c] += grid[r][c-1];
            }
        }
        for (int c = 1; c <= n; c++) {
            for (int r = 1; r <= n; r++) {
                grid[r][c] += grid[r-1][c];
            }
        }


        //     k   c
        // . . - - - . . .
        // . . - - -  . . .
        // . . . . . . . .
        // best[lo][hi] => max of ([(0, 0), (x, lo-1)] - [(0,lo), (x, hi)]) for all x < r
        vector<vector<int>> best(n+1, vector<int>(n+1, -1e8));

        for (int r = 0; r <= n; r++) {
            for (int hi = 1; hi <= n; hi++) {
                // assume (r, c) is the endpoint of a subgrid
                for (int lo = 1; lo <= n; lo++) {
                    // find another point (x, k) (x <= r) maximizing the subgrid
                    res = max(res, grid[r][hi] + best[lo][hi] - grid[r][lo-1]);
                }
            }
            for (int lo = 1; lo <= n; lo++) {
                for (int hi = lo; hi <= n; hi++) {
                    best[lo][hi] = max(best[lo][hi], grid[r][lo-1] - grid[r][hi]);
                }
            }
        }

        // for (int c = 0; c <= n; c++) {
        //     for (int k = 0; k <= n; k++) {
        //         cout << setw(4) << best[c][k] << " ";
        //     }
        //     cout << "\n";
        // }

        cout << res << "\n";

        
    }
}
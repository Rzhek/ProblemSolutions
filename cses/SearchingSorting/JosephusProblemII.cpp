#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vii grid;
    int root = sqrt(n);

    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        tmp.push_back(i);
        if (tmp.size() > root || i == n) {
            grid.push_back(tmp);
            tmp.clear();
        }
    }

    int row = 0, col = 0;
    for (int i = 0; i < n; i++) {
        int j = k % (n - i);
        while (j) {
            if (col + j < grid[row].size()) {
                col += j;
                j = 0;
            } else {
                j -= grid[row].size() - col;
                col = 0;
                row++;
                row %= grid.size();
            }
        }
        
        cout << grid[row][col] << " ";
        if (i != n - 1) {
            grid[row].erase(grid[row].begin() + col);
            if (col >= grid[row].size()) {
                if (grid[row].size() == 0) {
                    grid.erase(grid.begin() + row);
                } else {
                    row++;
                }
                col = 0;
                row %= grid.size();
            }
        }
    }
    cout << '\n';
    return 0;
}
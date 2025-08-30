#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vll = vector<vl>;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vll grid(n + 1, vl(n + 1, 0));
    grid[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch; cin >> ch;
            if (ch == '*') {
                grid[i][j] = 0;
                continue;
            } 
            grid[i+1][j] += grid[i][j]; grid[i+1][j] %= MOD;
            grid[i][j+1] += grid[i][j]; grid[i][j+1] %= MOD;
        }
    }

    cout << grid[n-1][n-1] << '\n';
    return 0;
}
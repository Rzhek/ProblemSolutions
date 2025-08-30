#include <bits/stdc++.h>
using namespace std;

// using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    // vector<string> grid(n);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char ch; cin >> ch;
            int color = (r + 1000 - c) % 2;
            if (color == 0 && ch == 'A') cout << 'B';
            else if (color == 0) cout << 'A';
            else if (color == 1 && ch == 'C') cout << 'D';
            else cout << 'C';
        }
        cout << "\n";
    }
}
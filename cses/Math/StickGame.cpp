#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> canWin(n + 1), guys(k);
    string out = "LW";
    for (int &x : guys) cin >> x;

    for (int i = 1; i <= n; i++) {
        for (int di : guys) {
            if (canWin[i] |= i - di >= 0 && !canWin[i-di]) break;
        }
        cout << out[canWin[i]];
    }
    cout << "\n";
}

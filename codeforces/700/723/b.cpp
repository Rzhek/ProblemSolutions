#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n >= 111*(n%11)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
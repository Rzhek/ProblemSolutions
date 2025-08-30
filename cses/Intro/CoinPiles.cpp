#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a1, b1; cin >> a1 >> b1;
        int a = min(a1, b1), b = max(a1, b1);
        
        if ((a + b) % 3 == 0 && (b - a <= a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
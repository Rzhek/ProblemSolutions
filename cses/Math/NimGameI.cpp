#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int res = 0;
        while (n--) {
            int x; cin >> x;
            res ^= x;
        }
        if (res) cout << "first\n";
        else cout << "second\n";
    }
}
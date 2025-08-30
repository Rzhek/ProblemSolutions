#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        int res = 1;
        for (int y = 1; y < x; y++) {
            if (__gcd(res, x) + res < __gcd(x, y) + y) {
                res = y;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
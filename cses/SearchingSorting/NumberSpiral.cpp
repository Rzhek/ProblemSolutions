#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        ll y, x; cin >> y >> x;
        ll res;
        if (y > x) {
            if (y % 2 == 0) {
                res = y * y - x + 1;
            } else {
                res = (y - 1) * (y - 1) + 1 + x - 1;
            }
        } else {
            if (x & 1) {
                res = x * x - y + 1;
            } else {
                res = (x - 1) * (x - 1) + 1 + y - 1;
            }
        }


        cout << res << '\n';
    }
    return 0;
}
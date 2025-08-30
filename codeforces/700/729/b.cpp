#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        ll n, a, b; cin >> n >> a >> b;
        int found = 0;
        for (int x = 0; x <= 32; x++) {
            ll ax = pow(a, x);
            if (ax > n) break;
            ll y = n - ax;
            if (y % b == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }

    return 0;
}
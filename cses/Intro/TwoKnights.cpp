#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll res = k * k * (k * k - 1) / 2;
        ll num3by2 = max((ll)0, k - 2) * max((ll)0, k - 1);
        res -= num3by2 * 4;
        cout << res << '\n';
    }

    return 0;
}
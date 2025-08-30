#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll res = 0;
        ll x, y, a, b; cin >> x >> y >> a >> b;
        while (y > 0) {
            ll d = x * (b - a) / a;
            // if (d > 1)
            // cout << d << endl;
            if (d <= 0) {
                res = -1;
                break;
            }
            y -= d;
            res++;
        }
        cout << "res: " << res << endl;
    }

    return 0;
}
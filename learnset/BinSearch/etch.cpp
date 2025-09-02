#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld EPS = 1e-4;

inline ld get(ld a, ld b, ld c, ld t) {
    return a * t + b * (1 - pow(exp(1.0), -c * t));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt; cin >> tt;
    for (int tc = 1; tc <= tt; tc++) {
        ld f1, f2, a, b, c; cin >> f1 >> f2 >> a >> b >> c;
        ld target = (f2 - f1) / (f1 * f2);

        ld lo = 0, hi = 1e7;

        while ((hi - lo) > EPS) {
            ld m = (hi + lo) / 2;
            if (get(a, b, c, m) > target) hi = m;
            else lo = m;
        }
        
        cout << "Crystal #" << tc << ": " << fixed << setprecision(2) << hi << "\n\n"; 
    }
}
#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using vl = vector<ld>;

ld query(vl &arr, int l, int r) {
    return arr[r] - (l ? arr[l-1] : 0);
}

ld calc(ld lambda, ld B, ld K, int M, ld X, ld Y, ld X2, ld Y2, ld XY) {
    return lambda * (B * B + K * K) + K * K * X2 + 2 * K * B * X + B * B * M - 2 * K * XY - 2 * B * Y + Y2;
}

ld calc2(int M, ld Y, ld K, ld X, ld lambda) {
    return (Y - K * X) / (lambda + M);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vl X(n), Y(n), X2(n), Y2(n), XY(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        X2[i] = X[i] * X[i];
        Y2[i] = Y[i] * Y[i];
        XY[i] = X[i] * Y[i];
    }
    // cout << X[0] << " ";
    for (int i = 1; i < n; i++) {
        X[i] += X[i-1];
        Y[i] += Y[i-1];
        X2[i] += X2[i-1];
        Y2[i] += Y2[i-1];
        XY[i] += XY[i-1];
        // cout << X[i] << " ";
    }
    // cout << "\n";

    int m; cin >> m;

    while (m--) {
        int L, R; ld lambda, q; cin >> L >> R >> lambda >> q;

        ld x = query(X, L-1, R-1);
        ld y = query(Y, L-1, R-1);
        ld x2 = query(X2, L-1, R-1);
        ld y2 = query(Y2, L-1, R-1);
        ld xy = query(XY, L-1, R-1);
        int M = (R - L + 1);

        // cout << x << " " << y << " " << x2 << " " << y2  << " " << xy << "\n";

        ld lo = -10000, hi = 10000;
        for (int i = 0; i < 200; i++) {
            ld k1 = lo + (hi - lo) / 3, k2 = hi - (hi - lo) / 3;
            ld B1 = calc2(M, y, k1, x, lambda);
            ld B2 = calc2(M, y, k2, x, lambda);

            // cout << k1 << " " << B1 << " " << k2 << " " << B2 << ": " << calc(lambda, B1, k1, M, x, y, x2, y2, xy) << " " << calc(lambda, B2, k2, M, x, y, x2, y2, xy) << "\n";
            

            if (calc(lambda, B1, k1, M, x, y, x2, y2, xy) <= calc(lambda, B2, k2, M, x, y, x2, y2, xy)) {
                hi = k2;
            } else {
                lo = k1;
            }
        }
        cout << fixed << setprecision(7) << (lo * q) + calc2(M, y, lo, x, lambda) << "\n";

        // cout << calc(lambda, 1, 1, M, x, y, x2, y2, xy) << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        double m, d; cin >> m >> d;
        double res = 0;
        for (int i = 0; i < m; i++) {
            double s; cin >> s;
            res += d / s;
        }
        cout << fixed << setprecision(2) << res << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int r1, g1, b1; cin >> r1 >> g1 >> b1;
    int r2, g2, b2; cin >> r2 >> g2 >> b2;
    
    int rg, gb; cin >> rg >> gb;

    r1 -= r2;
    g1 -= g2;
    b1 -= b2;

    int ans = 0;
    if (r1 > 0) {
        ans += r1;
        rg -= r1;
    }
    if (b1 > 0) {
        ans += b1;
        gb -= b1;
    }

    if (g1 > 0) {
        int left = max(0, rg) + max(0, gb);
        ans += min(left, g1);
        g1 -= min(left, g1);
    }

    if (rg < 0 || gb < 0 || g1 > 0) ans = -1;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << solve() << "\n";
}
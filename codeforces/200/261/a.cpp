#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2 - x1, dy = y2 - y1;
    if (dx == 0) {
        cout << x1 + dy << " " << y1 << " ";
        cout << x2 + dy << " " << y2 << "\n";
    } else if (dy == 0) {
        cout << x1 << " " << y1 + dx << " ";
        cout << x2 << " " << y2 + dx << "\n";
    } else if (abs(dx) == abs(dy)) {
        cout << x1 << " " << y1 + dy << " ";
        cout << x2 << " " << y2 - dy << "\n";
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ld r, x1, y1, x2, y2; cin >> r >> x1 >> y1 >> x2 >> y2;
    ld dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << ceil(dist / (2 * r)) << '\n';
}
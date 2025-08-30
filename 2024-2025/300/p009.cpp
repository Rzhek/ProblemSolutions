#include <bits/stdc++.h>
using namespace std;

using ld = long double;

struct P {
    int x, y;
    explicit P(int x = 0, int y = 0): x(x), y(y) {}
    P operator-(P p) { return P(x - p.x, y - p.y); }
    int dist2() const { return x * x + y * y; }
    ld dist() const { return sqrt(dist2()); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<P> pts(n + 1);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    int m; cin >> m;

    vector<vector<ld>> dp(n + 1, vector<ld>(1 << n));
}
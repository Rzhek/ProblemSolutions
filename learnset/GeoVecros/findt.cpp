#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld EPS = 1e-6;


struct P {
    ld x, y;

    explicit P(ld x = 0, ld y = 0) : x(x), y(y) {}
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(ld d) const { return P(x * d, y * d); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    ld dot(P o) const { return x * o.x + y * o.y; }
    ld cross(P o) const { return x * o.y - y * o.x; }
    ld cross(P a, P b) const { return (a - *this).cross(b-*this); }
    ld dist2() const { return x * x + y * y; }
    ld dist() const { return sqrt(dist2()); }

    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};


double segDist(P& s, P& e, P& p) {
    if (s == e) return (p - s).dist();
    auto d = (e - s).dist2(),
        t = min(d, max((ld).0, (p - s).dot(e - s)));
    return ((p - s) * d - (e - s) * t).dist() / d;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n; cin >> n;
        vector<P> pts(n);
        for (int i = 0; i < n; i++) {
            // string x, y; cin >> x >> y;
            // pts[i] = P(stold(x), stold(y));
            cin >> pts[i].x >> pts[i].y;
        }

        int res = 0;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                for (int m = 0; m < n; m++) {
                    if (m == a || m == b) continue;

                    if (segDist(pts[a], pts[b], pts[m]) <= EPS && abs((pts[m]-pts[a]).dist() - (pts[b]-pts[m]).dist()) <= EPS) {
                        ld AB = (pts[b]-pts[a]).dist();
                        for (int c = 0; c < n; c++) {
                            if (c == a || c == b || c == m) continue;

                            if (abs((pts[m]-pts[c]).dot(pts[a]-pts[m])) <= EPS) res += fabs((pts[m]-pts[c]).dist() - AB) <= EPS;
                        }
                    }
                }
            }
        }

        cout << "Set #" << cs << ": " << res << "\n\n";
        

    }
}
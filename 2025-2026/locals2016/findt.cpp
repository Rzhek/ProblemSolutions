#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld EPS = 1e-6;

#define equal(xx, yy) (abs(xx-yy) < EPS)

template<class T> struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0): x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const {
        return (a - *this).cross(b - *this);
    }
    T dist2() const { return x * x + y * y; }
};

using P = Point<ld>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int n; cin >> n;
        vector<P> pts(n);
        for (auto &p : pts) {
            ld x, y; cin >> x >> y;
            p.x = x;
            p.y = y;
        }

        int res = 0;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (a == b) continue;
                for (int c = 0; c < n; c++) {
                    if (c == a || c == b) continue;

                    // check that m is in between a and b
                    P A = pts[a], B = pts[b], C = pts[c];

                    // if ((A-C).dist2() != (B-C).dist2()) continue;
                    if (!equal((A-C).dist2(), (B-C).dist2())) continue;
                    // if ((B-A).cross((C-A)) != 0) continue;
                    if (abs((B-A).cross((C-A))) >= EPS) continue;

                    for (int m = 0; m < n; m++) {
                        if (m == a || m == b || m == c) continue;
                        
                        P M = pts[m];
                        
                        // if ((M-C).dist2() != (A-B).dist2()) continue;
                        if (!equal((M-C).dist2(), (A-B).dist2())) continue;
                        if (abs((M-C).dot(A-C)) >= EPS) continue;
                        // if ((M-C).dot(A-C) != 0) continue;
                        res++;

                    }
                }
            }
        }

        cout << "Set #" << t << ": " << res / 2<< "\n\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

struct P {
    double x, y;
    explicit P(double x = 0, int y = 0): x(x), y(y) {}
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(double d) const { return P(x * d, y * d); }
    P operator/(double d) const { return P(x / d, y / d); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    double dot(P p) const { return x * p.x + y * p.y; }
    double cross(P p) const { return x * p.y - y * p.x; }
    double dist2() const { return x * x + y * y; }
    double dist() const { return sqrt(dist2()); }
    P perp() const { return P(-y, x); }
    double angle() const { return atan2(y, x); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

double intersection(double r1, double r2, double d) {
    if (r1 > r2) swap(r1, r2);

    if (d >= r1 + r2) return 0;
    if (d <= r1 - r2) return r1 * r1 * PI;


    double theta1 = 2 * acos(max(-1.0, min(1.0, (d*d + r1 * r1 - r2 * r2) / (2 * d * r1))));
    double theta2 = 2 * acos(max(-1.0, min(1.0, (d*d + r2 * r2 - r1 * r1) / (2 * d * r2))));


    double area1 = 0.5 * r1 * r1 * (theta1 - sin(theta1));
    double area2 = 0.5 * r2 * r2 * (theta2 - sin(theta2));

    if (d < r2) area1 = PI * r1 * r1 - area1;

    return area1 + area2;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n; cin >> n;

        P lastP(-1e9, -1e9);
        double lastR = 0;
        double res = 0;
        
        while (n--) {
            P cur; cin >> cur.x >> cur.y;
            double r; cin >> r;

            res += PI * r * r;
            res -= intersection(lastR, r, (cur-lastP).dist());
            lastP = cur;
            lastR = r;
        }

        cout << fixed << setprecision(2) << "Set #" << tt << ": " << res << "\n\n";
    }

}
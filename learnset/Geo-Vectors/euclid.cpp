#include <bits/stdc++.h>
using namespace std;

struct P {
    double x, y;
    explicit P(double x = 0, double y = 0) : x(x), y(y) {}
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator/(double v) const { return P(x / v, y / v); }
    P operator*(double v) const { return P(x * v, y * v); }
    double cross(P p) const { return x * p.y - y * p.x; }
    double cross(P a, P b) const { return (a - *this).cross(b - *this); }
    double dist2() const { return x * x + y * y; }
    double dist() const { return sqrt(dist2()); }
    P perp() const { return P(-y, x); }
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }

    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        P a, b, c, d, e, f;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        cin >> d.x >> d.y >> e.x >> e.y >> f.x >> f.y;
        vector<double> tmp = {a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y, e.x, e.y, f.x, f.y};
        if (accumulate(tmp.begin(), tmp.end(), (double)0) == 0 && *max_element(tmp.begin(), tmp.end()) == 0) return 0;

        P lo = a, hi = c;
        while (abs(hi.x) < 1000 && abs(hi.y) < 1000) hi = a + (hi-a) * 2;

        double target = abs((e-d).cross(f-d)) / 2;

        double k = target / abs((c-a).cross(b-a));

        P h = a + (c-a) * k;
        P g = b + h - a;

        cout << fixed << setprecision(3) << g.x << " " << g.y << " " << h.x << " " << h.y << "\n";

    }
}
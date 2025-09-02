#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)

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

pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    if (d == 0)
        return {-(s1.cross(e1, s2) == 0), P(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}

double area;
P solve(P a, P b, P p) {
    if (a.x == b.x) {
        P res = solve(a.perp(), b.perp(), p.perp());
        return res.perp().perp().perp();
    }
    if (a.x > b.x) swap(a, b);

    P lo = a, hi = b, m;
    for (int i = 0; i < 500; i++) {
        m = (lo+hi)/2;
        P res;

        P vec = m + (b-m).perp();
        auto res1 = lineInter(m, vec, a, p);
        auto res2 = lineInter(m, vec, b, p);
        // assert(res1.first && res2.first);

        double test;
        if ((res1.second-m).dist2() < (res2.second-m).dist2()) {
            test = abs((m-a).cross(res1.second-a)) / 2;
        } else {
            test = area - abs((m-b).cross(res2.second-b)) / 2;
        }

        if (test * 2 > area) hi = m;
        else lo = m; 
    }
    return m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for (int idk = 1; idk <= t; idk++) {
        P a, b, c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

        area = abs(((b-a).cross(c-a))) / 2;

        double ab = (a-b).dist2();
        double bc = (b-c).dist2();
        double ac = (a-c).dist2();
        double maxi = max({ab, bc, ac});

        P res;
        if (ab == maxi) res = solve(a, b, c);
        else if (bc == maxi) res = solve(b, c, a);
        else res = solve(a, c, b);

        cout << fixed << setprecision(2) << "Triangle #" << idk << " Balance Point: (" << res.x << "," << res.y << ")\n"; 
        
    }
}
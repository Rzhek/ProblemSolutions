#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

template<class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T> struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
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
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> int segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
        oc = a.cross(b, c), od = a.cross(b, d);
    
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) return 1;
    if (onSegment(c, d, a)) return 1; 
    if (onSegment(c, d, b)) return 1; 
    if (onSegment(a, b, c)) return 1; 
    if (onSegment(a, b, d)) return 1;
    return 0;
}

vector<Point<int>> convexHull(vector<Point<int>> pts) {
    typedef Point<int> P;
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts) + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
    for (P p : pts) {
        while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
        t--;
        h[t++] = p;
    }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

using P = Point<double>;
bool solve(vector<P> &poly, double m) {
    bool works = false;
    for (int i = 1; !works && i < 2; i++) {
        P a = poly[i], b = poly[(i+1)%sz(poly)];

        cout << a + (b-a).normal() * m << "\n";
        P s = a + (b-a).normal() * m - (b-a).unit() * 1;
        P e = a + (b-a).normal() * m + (b-a).unit() * 1;

        cout << s << " " << e << "\n";
        
        bool tmp = true;
        for (int j = 0; tmp && j < sz(poly); j++) {
            tmp &= segInter(poly[j], poly[(j+1)%sz(poly)], s, e) == 0;
        }
        works |= tmp;
    }
    return works;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(2);
    int n, t = 1;

    for (cin >> n; n; cin >> n, t++) {
        vector<Point<int>> poly(n);
        for (auto &p : poly) cin >> p.x >> p.y;
        vector<Point<double>> hull; 
        for (auto p : convexHull(poly)) hull.push_back(P(p.x, p.y));

        double lo = 0, hi = 1e4+10;

        // for (int i = 0; i < 400; i++) {
        //     double m = (lo + hi) / 2;
        //     if (solve(hull, m)) hi = m;
        //     else lo = m;
        // }
        // lo = ceil(lo * 100) / 100.0;
        // cout << "Case #" << t << ": " << lo << "\n";

        cout << solve(hull, 2.96) << "\n";
    }
}
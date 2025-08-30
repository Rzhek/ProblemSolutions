#include <bits/stdc++.h>
using namespace std;

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

using P = Point<double>;

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

vector<P> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
    oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    return {(a * ob - b * oa) / (ob - oa)};
    set<P> s;
    return {};
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return {all(s)};
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int n, k; cin >> n >> k;
        vector<P> pts(n);
        for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

        double res1 = 0, res2 = 0;
        vector<P> bounds;

        for (int i = 0; i < n; i++) {
            P a = pts[i], b = pts[(i+1)%n];

            auto res = segInter(a, b, P(-1005, k), P(1005, k));
            if (res.size() == 0) {
                res1 += (a-b).dist();
            } else if (res.size() == 1) {
                res1 += (a-res[0]).dist();
                res2 += (b-res[0]).dist();
                swap(res1, res2);
                bounds.push_back(res[0]);
            } else {
                assert(false);
            }
        }

        assert(bounds.size() == 2);
        if (res1 > res2) swap(res1, res2);
        res1 += (bounds[0]-bounds[1]).dist();
        res2 += (bounds[0]-bounds[1]).dist();

        cout << fixed << setprecision(3) << "Case #" << t << ": " << res1 << " " << res2 << "\n\n"; 

    }
}
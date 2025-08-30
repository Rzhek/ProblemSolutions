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

void add(P a, P b, P c, vector<pair<double, double>> &res) {
    double area = abs(a.cross(b, c)) / 2.0;
    double per = (a-b).dist() + (b-c).dist() + (a-c).dist();
    res.emplace_back(round(area * 1000)/1000.0, round(per*1000)/1000.0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(3);
    while (1) {
        P p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        P maxi = max({p1, p2, p3, p4}), mini = max({p1, p2, p3, p4});
        if (maxi == mini && maxi == P(0, 0)) break;


        vector<pair<double, double>> res;

        P p5 = segInter(p1, p3, p2, p4)[0];

        add(p1, p2, p5, res);
        add(p2, p3, p5, res);
        add(p3, p4, p5, res);
        add(p4, p1, p5, res);

        sort(res.begin(), res.end(), [&](auto a, auto b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        });

        for (auto [a, p] : res) cout << a << " " << p << " ";
        cout << "\n";

    }
}
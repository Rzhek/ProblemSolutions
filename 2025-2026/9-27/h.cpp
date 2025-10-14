#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define sz(x) (ll)(x).size()
#define rep(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

template<class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T> struct Point {
    typedef Point P;
    T x,y;
    explicit Point(T x = 0, T y = 0): x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x,y) < tie(p.x,p.y);
    }
    bool operator==(P p) const {
        return tie(x,y) == tie(p.x,p.y);
    }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x);}
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x*cos(a) - y * sin(a), x*sin(a)+y*cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

typedef Point<double> P;

pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1-s1).cross(e2-s2);
    if(d == 0) return {-(s1.cross(e1,s2) == 0), P(0,0)};
    auto p = s2.cross(e1,e2), q = s2.cross(e2,s1);
    return {1, (s1*p+e1*q)/d};
}

long double polyArea(vector<P> poly) {
    long double a = poly.back().cross(poly[0]);
    rep(i, 0, sz(poly) - 1) a += poly[i].cross(poly[i+1]);
    return abs(a/2);
}

vector<P> polygonCut(vector<P> poly, P s, P e) {
    vector<P> res;
    rep(i,0,sz(poly)) {
        P cur = poly[i], prev = i ? poly[i-1] : poly.back();
        bool side = s.cross(e,cur) < 0;
        if(side != (s.cross(e,prev) < 0)) res.push_back(lineInter(s,e,cur,prev).second);
        if(side) res.push_back(cur);
    }
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<P> poly(4);
    for (auto &[x, y] : poly) cin >> x >> y;

    long double res = 0;

    res += 5 * 1 * polyArea(polygonCut(poly, P(-.5,-.5), P(.5,-.5)));
    res += 5 * 6 * polyArea(polygonCut(poly, P(.5,.5), P(-.5,.5)));
    res += 5 * 4 * polyArea(polygonCut(poly, P(-.5,.5), P(-.5,-.5)));
    res += 5 * 3 * polyArea(polygonCut(poly, P(.5,-.5), P(.5,.5)));
    res += 4 * 5 * 25;

    cout << fixed << setprecision(8) << res / (5 * 5 * 5 - 1) << "\n";

}
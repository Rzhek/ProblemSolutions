#include <bits/stdc++.h>
using namespace std;

template<class T> int sgn(T x) { return (x > 0) - (x < 0); }
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

template<class P>
long double lineDist(P &a, P &b, P &p) {
    return (double)(b - a).cross(p - a) / (b - a).dist();
}

typedef Point<long long> P;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, p; cin >> n >> p;
    if (n == 1) {
        cout << "possible\n";
        return 0;
    }
    mt19937 mt(time(nullptr));
    vector<P> points;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points.push_back(P(x, y));
    }

    for (int i = 0; i < 300; i++) {
        int ind1, ind2;
        ind1 = ind2 = mt() % n;
        while (ind2 == ind1) {
            ind2 = mt() % n;
        }
        int count = 0;
        for (P point : points) {
            if (lineDist(points[ind1], points[ind2], point) == 0) count++;
        }
        if (count >= ((n*p)/100 + (bool)((n*p)%100))) {
            cout << "possible\n";
            return 0;
        }
    }
    cout << "impossible\n";
    return 0;
}
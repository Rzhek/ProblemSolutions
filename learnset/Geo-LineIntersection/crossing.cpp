#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

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
    // angle to x=axis in interval [= pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); } // makes d i s t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

using P = Point<double>;

template<class P> pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    if (d == 0)
        return {-(s1.cross(e1, s2) == 0), P(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}

#define abs1(x) abs(90 - x)

bool inter(int x1, int a1, int x2, int a2) {
    if (x1 > x2) return inter(x2, a2, x1, a1);
    if (a1 >= a2) return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    for (cin >> n; n; cin >> n) {

        vector<tuple<P, int, int>> data(n);
        for (int i = 0; i < n; i++) {
            auto &[p, ang, idx] = data[i];
            cin >> p.x;
            idx = i;
        }
        for (int i = 0; i < n; i++) {
            auto &[p, ang, idx] = data[i];
            cin >> ang;
        }

        sort(data.begin(), data.end(), [](auto &a, auto &b) {
            auto &[p1, ang1, idx1] = a;
            auto &[p2, ang2, idx2] = b;
            if (abs1(ang1) != abs1(ang2)) return abs1(ang1) < abs1(ang2);
            return idx1 < idx2;
        });

        vector<tuple<P, int, int>> res;
        vector<int> out;

        vector<pair<int, int>> dead;

        for (auto [p1, ang1, idx1] : data) {
            int works = true;
            for (auto [l, r] : dead) {
                if (l <= p1.x && p1.x <= r) works = false;
            }
            if (!works) continue;
            int maxi = -1e9;
            int mini = 1e9;
            for (auto [p2, ang2, idx2] : res) {
                if (idx1 == idx2) break;
                if (inter(p1.x, ang1, p2.x, ang2)) {
                    works = false;
                    maxi = max(maxi, (int)p2.x);
                    mini = min(mini, (int)p2.x);
                }
            }

            if (works) {
                res.emplace_back(p1, ang1, idx1);
                // out.push_back(idx1);
            } else {
                if (p1.x < mini) dead.emplace_back(p1.x, mini);
                else dead.emplace_back(maxi, p1.x);
            }
        }

        // for (auto [l, r] : dead) cout << l << " " << r << "\n";

        for (auto [a, b, c] : res) out.push_back(c);

        cout << out.size() << "\n";
        sort(out.begin(), out.end());
        for (int x : out) cout << x << " ";
        cout << "\n";

        // LOCK IN IN IN

    }
}
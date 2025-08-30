#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using iii = tuple<int, int, int>;

const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-7;

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

template<class T> T polygonArea2(vector<Point<T>>& v) {
    T a = v.back().cross(v[0]);
    rep(i, 0, sz(v) - 1) a += v[i].cross(v[i+1]);
    return a;
}

using P = Point<ld>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<P> points(n);
    forn(i, n) {
        ll x, y; cin >> x >> y;
        points[i] = P(x, y);
    }

    ld totalArea = abs(polygonArea2(points)) / 2;
    ld targetArea = totalArea / 2;
    ld lx, ly, hx, hy;
    ld initialArea = 0;
    vector<P> dPoly = {points[0]};

    for (int i = 1; i < n - 1; i++) {
        vector<P> poly = {points[0], points[i], points[i+1]};
        ld dArea = abs(polygonArea2(poly)) / 2;
        if (initialArea + dArea >= targetArea) {
            lx = points[i].x;
            ly = points[i].y;
            hx = points[i+1].x;
            hy = points[i+1].y;
            dPoly.pb(points[i]);
            break;
        }
        initialArea += dArea;
    }

    ld prevX = 1e9, prevY = 1e9;
    for (int i = 0; i < 10000; i++) {
        ld mx = (lx+hx)/2, my = (ly+hy)/2;
        prevX = mx; prevY = my;
        dPoly.pb(P(mx, my));
        ld dArea = abs(polygonArea2(dPoly)) / 2;
        dPoly.pop_back();
        if (abs(initialArea + dArea - targetArea) < EPS) break;
        if (initialArea + dArea < targetArea) {
            lx = mx;
            ly = my;
        } else {
            hx = mx;
            hy = my;
        }
    }

    cout << fixed << setprecision(7) << prevX << " " << prevY << "\n";
    return 0;
}
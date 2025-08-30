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
const long double EPS = 1e-9;


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
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
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

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
    if (s == e) return (p - s).dist();
    auto d = (e - s).dist2(), t = min(d, max(.0, (p - s).dot(e - s)));
    return ((p - s) * d - (e - s) * t).dist() / d;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vpi pts1(n);
    vector<ld> dist1(n, 0);
    forn (i, n) {
        cin >> pts1[i].f >> pts1[i].s;
        if (i) dist1[i] = dist1[i-1] + sqrt(pow((pts1[i].f - pts1[i-1].f), 2) + pow((pts1[i].s - pts1[i-1].s), 2));
    }


    int m; cin >> m;
    vpi pts2(m);
    vector<ld> dist2(m);
    forn (i, m) {
        cin >> pts2[i].f >> pts2[i].s;
        if (i) dist2[i] = dist2[i-1] + sqrt(pow((pts2[i].f - pts2[i-1].f), 2) + pow((pts2[i].s - pts2[i-1].s), 2));
    }

    map<ld, pair<ld, ld>> times;
    for (ld a : dist1) {
        times[a] = {0, 0};
    }
    for (ld a : dist2) {
        times[a] = {0, 0};
    }

    int lastInd = 0;
    for (auto [t, d] : times) {
        while (lastInd + 1 < m && dist2[lastInd+1] < t) lastInd++;
        if (lastInd + 1 == m) break;
        ld x1 = pts2[lastInd].f;
        ld y1 = pts2[lastInd].s;
        ld x2 = pts2[lastInd+1].f;
        ld y2 = pts2[lastInd+1].s;
        ld t1 = dist2[lastInd];
        ld t2 = dist2[lastInd+1];
        ld dx = x2 - x1, dy = y2 - y1, dt = t2 - t1;
        times[t].f += x1 + ((t - t1) ? (x2 - x1) * (t - t1) / (t2 - t1) : 0);
        times[t].s += y1 + ((t - t1) ? (y2 - y1) * (t - t1) / (t2 - t1) : 0);
    }
    lastInd = 0;
    for (auto [t, d] : times) {
        while (lastInd + 1 < n && dist1[lastInd+1] < t) lastInd++;
        if (lastInd + 1 == n) break;
        ld x1 = pts1[lastInd].f;
        ld y1 = pts1[lastInd].s;
        ld x2 = pts1[lastInd+1].f;
        ld y2 = pts1[lastInd+1].s;
        ld t1 = dist1[lastInd];
        ld t2 = dist1[lastInd+1];
        times[t].f -= x1 + ((t - t1) ? (x2 - x1) * (t - t1) / (t2 - t1) : 0);
        times[t].s -= y1 + ((t - t1) ? (y2 - y1) * (t - t1) / (t2 - t1) : 0);
    }
    
    double res = 1e5;
    P center = P(0, 0);
    for (auto it = times.begin(); it != times.end(); ) {
        P a = P(it->s.f, it->s.s);
        it++;
        if (it == times.end()) break;
        P b = P(it->s.f, it->s.s);
        if (it->f > min(dist1.back(), dist2.back())) break;
        // cout << it->f << ": " << a << " " << b << " -> " <<segDist(a, b, center) << "\n";
        res = min(res, segDist(a, b, center));
    }

    assert(res != 1e5);
    cout << fixed << setprecision(6) << res << "\n";
    return 0;
}
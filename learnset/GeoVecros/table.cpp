#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define EPS (1e-3)
using ll = long double;

struct P {
    ll x, y;
    explicit P(ll x = 0, ll y = 0): x(x), y(y) {}
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(ll a) const { return P(x * a, y * a); }
    P operator/(ll a) const { return P(x / a, y / a); }
    ll cross(P p) const { return x * p.y - y * p.x; };
    ll dot(P p) const { return x * p.x + y * p.y; }
    ll dist2() const { return x * x + y * y; }
    double dist() const { return sqrt(dist2()); }
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

double angleRad(P a, P b) {
    ll area = a.cross(b);
    if (area <= 0) return 0;
    if (a.dot(b) >= 0) return PI - asin(area / a.dist() / b.dist());
    return asin(area / a.dist() / b.dist());
}

vector<P> pts;
set<pair<int, int>> res;
vector<vector<vector<int>>> adj;

bool solve(int i, int j, int first) {
    if (res.count({i, j})) return false;
    if (j == first) return true;

    for (int k : adj[i][j]) {
        // if (abs((pts[k]-pts[j]).dist2() -(pts[j]-pts[i]).dist2()) < EPS) {
            return solve(j, k, first);
        // }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        pts = vector<P>(n);
        for (int i = 0; i < n; i++) {
            double x, y; cin >> x >> y;
            pts[i] = P(x * 1, y * 1);
        }

        double angleNeed = (k - 2) * PI / k;

        adj = vector<vector<vector<int>>>(n, vector<vector<int>>(n));
        // adj[i][j] = {set of k}

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;
                    // find angle between ij and jk
                    P v1 = pts[j] - pts[i];
                    P v2 = pts[k] - pts[j];

                    double angle = angleRad(v1, v2);
                    if (abs(angle - angleNeed) > EPS) continue;
                    // cout << v1 << " " << v2 << "\n";
                    if (abs(v1.dist() - v2.dist()) >= EPS) continue;
                    // cout << pts[i] << " " << pts[j] << " " << pts[k] << ": " << angle << " ->" << angle * 180 / PI << "\n";
                    adj[i][j].push_back(k);
                }
            }
        }
        res.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                // cout << i << " " << j << "\n";
                if (solve(i, j, i)) res.insert({i, j});
            }
        }

        cout << res.size() << "\n";
        // for (auto [i, j] : res) {
        //     cout << pts[i] << " " << pts[j] << "\n";
        // }

    }



}
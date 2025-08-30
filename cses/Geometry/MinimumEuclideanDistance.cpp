#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
struct P {
    ll x, y;
    explicit P(ll x = 0, ll y = 0): x(x), y(y) {}
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    bool operator<(P p) const { return tie(y, x) < tie(p.y, p.x); }
    bool operator==(P p) const { return tie(y, x) == tie(p.y, p.x); }
    ll dist2() const { return x * x + y * y; }
    double dist() const { return sqrt(dist2()); }
    friend ostream& operator<<(ostream &os, P p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<P> pts(n);
    for (auto &p : pts) cin >> p.x >> p.y;
 
    sort(pts.begin(), pts.end(), [](auto a, auto b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    set<P> st;
    st.insert(pts[0]);
 
    int l = 0;
    unsigned long long res = 1e19;
    for (int r = 1; r < n; r++) {
 
        ll dist = sqrt(res) + 1;
        while (l < r && pts[l].x + dist < pts[r].x) {
            st.erase(pts[l++]);
        }
 
        auto lb = st.lower_bound(P(0, pts[r].y - dist));
        auto ub = st.upper_bound(P(0, pts[r].y + dist));
 
        for (; lb != ub; lb++) {
            res = min(res, (unsigned long long)(*lb-pts[r]).dist2());
        }
 
        st.insert(pts[r]);
 
    }
 
    cout << res << "\n";
}

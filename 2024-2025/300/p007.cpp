#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld EPS = 1e-3;

struct P {
    ld x, y, z;
    explicit P(ld x = 0, ld y = 0, ld z = 0): x(x), y(y), z(z) {}
    P operator+(P p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(P p) const { return P(x - p.x, y - p.y, z - p.z); }
    P operator*(ld d) const {return P(x * d, y * d, z * d); }
    P cross(P p) const { return P(
        y * p.z - z * p.y, 
        -(x * p.z - z * p.x), 
        x * p.y - y * p.x); 
    }
    ld dot(P p) const { return x * p.x + y * p.y + z * p.z; }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ld d; cin >> d;
    P plane1, plane2;
    cin >> plane1.x >> plane1.y >> plane1.z;
    cin >> plane2.x >> plane2.y >> plane2.z;
    P normal = plane1.cross(plane2);

    int res = 0;
    while (n--) {
        ld x, y, z; cin >> x >> y >> z; 
        ld dx, dy, dz; cin >> dx >> dy >> dz;
        
        P p = P(x, y, z) - P(dx, dy, dz) * d;

        if (abs(p.dot(normal)) < EPS) res++;
    }
    cout << res << "\n";
}
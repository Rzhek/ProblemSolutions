#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

struct P {
    int x, y;
    P(int a, int b) : x(a), y(b) {}

    double dist(P a) {
        int dx = a.x - x, dy = a.y - y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    for (cin >> n; n != 0; cin >> n) {
        vector<P> pts;
        set<int> free;
        forn (i, n) {
            int a, b; cin >> a >> b;
            pts.push_back(P(a, b));
            free.insert(i);
        }

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.emplace(0, 0);
        double res = 0;
        while (pq.size()) {
            auto [dw, u] = pq.top();
            pq.pop();
            if (free.find(u) == free.end()) continue;
            free.erase(u);
            res += dw;
            for (auto v : free) {
                pq.emplace(pts[u].dist(pts[v]), v);
            }
        }

        cout << fixed << setprecision(2) << res << "\n";
    }
    return 0;
}
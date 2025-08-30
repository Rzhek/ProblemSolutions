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


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, start1, start2; cin >> n >> start1 >> start2;
    set<pii> data;
    data.insert({start1, start2});
    forn (i, n) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        vpi good;
        for (auto it = data.lower_bound({a, c}); it != data.end() && it->first <= b;) {
            if (it->second < c || it->second > d) {
                it++;
                continue;
            }
            good.emplace_back(it->first, it->second);
            it++;
        }
        for (auto [x, y] : good) {
            data.insert({x+1, y});
            data.insert({x, y+1});
        }
        for (auto [x, y] : good) data.erase({x, y});
    }

    int best = 0;
    for (auto [x, y] : data) best = max(best, x - start1 + y - start2);
    cout << best << "\n";

    return 0;
}
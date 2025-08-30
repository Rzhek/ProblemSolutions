#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
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

set<pii> taken;
queue<pii> hanging;

void bfs(int X, int Y, int LVL) {
    queue<iii> q;
    set<pii> visited;
    for (int dx : {-1, 0, 1}) {
        for (int dy : {-1, 0, 1}) {
            q.emplace(X+dx, Y+dy, -1);
        }
    }

    while (q.size()) {
        auto [x, y, lvl] = q.front();
        q.pop();
        if (visited.count({x, y})) continue;
        visited.insert({x, y});
        if (lvl == LVL) {
            hanging.push({x, y});
            continue;
        }
        taken.insert({x, y});
        for (auto [dx, dy] : dirs) {
            if (visited.count({x+dx, y+dy})) continue;
            q.emplace(x+dx, y+dy, lvl+1);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    forn (i, n) {
        int x, y, lvl; cin >> x >> y >> lvl;
        bfs(x, y, lvl);
    }

    while (hanging.size()) {
        auto [x, y] = hanging.front();
        hanging.pop();
        if (taken.count({x, y})) continue;
        vvi square(3, vi(3));
        for (int dx : {-1, 0, 1}) {
            for (int dy : {-1, 0, 1}) {
                square[dx+1][dy+1] = taken.count({x+dx, y+dy});
            }
        }
        int count = 0;
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                if (square[i][j] + square[i+1][j] + square[i][j+1] + square[i+1][j+1] == 0) count++; 
            }
        }
        if (count == 0) {
            taken.insert({x, y});
            for (int dx : {-1, 0, 1}) {
                for (int dy : {-1, 0, 1}) {
                    hanging.emplace(x+dx, y+dy);
                }
            }
        }
    }

    cout << taken.size() << "\n";

    // for (int y = 130; y >= -10; y--) {
    //     for (int x = -20; x <= 20; x++) {
    //         if (taken.count({x, y})) cout << "#";
    //         else cout << ".";
    //     }
    //     cout << "\n";
    // }

    return 0;
}
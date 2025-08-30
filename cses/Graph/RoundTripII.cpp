#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
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

int n, m;
vvi edges;
vi visited, res;

int dfs(int cur, set<int> &route) {
    // if cycle found
    if (route.find(cur) != route.end()) {
        res.pb(cur);
        return cur;
    }
    
    // if we visited this node before and we couldnt find the cycle from this node
    // meaning there is no any cycle associated with this node
    if (visited[cur]) return -1;

    // add current node to our route and visit it
    route.insert(cur);
    visited[cur] = 1;

    // go through all of its neighbors
    for (int nxt : edges[cur]) {
        // try find cycle
        int ans = dfs(nxt, route);
        // -2 => cycle found, but current node is not a part of it
        if (ans == -2) return ans;
        // not -1 => cycle found and current node is a part of it 
        if (ans != -1) {
            res.pb(cur);
            if (cur == ans) return -2;
            return ans;
        }
        // otherwise keep searching
    }

    // if nothing found, delete current node from the route
    route.erase(cur);
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    edges.resize(n);
    visited.resize(n, 0);

    forn (i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].pb(b);
    }

    forn (i, n) {
        set<int> route;
        int ans = dfs(i, route);
        if (ans != -1) break;
    }

    if (res.size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(all(res));
    cout << res.size() << "\n";
    for (int x : res) cout << (x + 1) << " ";
    cout << "\n";
    return 0;
}
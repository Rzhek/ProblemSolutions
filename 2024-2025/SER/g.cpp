#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
#define f first
#define s second

template<class T>
ostream & operator << (ostream & os, vector<T> v) {
   for (auto x : v) os << x << ' '; cout << "\n";
   return os;
}
template<class T, class U>
ostream &operator << (ostream & os, pair<T, U> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

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
const int mod2inv = 500000004;
const long double EPS = 1e-9;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vvi adj(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vi visited(n);
    int res = 0;

    for (int i = 0; i < n; i++) {
        int sz = 0;
        queue<int> q({i});
        vi cur;
        while (q.size()) {
            int u = q.front(); q.pop();
            if (visited[u]) continue;
            cur.push_back(u);
            visited[u] = 1;
            sz++;
            for (int v : adj[u]) if (!visited[v]) {
                q.push(v);
            }
        }
        if (sz != k) continue;
        int works = 1;
        for (int u : cur) works &= adj[u].size() + 1 == k;
        res += works;
    }

    cout << res << "\n";
}
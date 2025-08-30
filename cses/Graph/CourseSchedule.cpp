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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vvi edges(n);
    vi indegree(n, 0);
    forn (i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].pb(b);
        indegree[b]++;
    }

    queue<int> q;
    forn (i, n) {
        if (indegree[i] == 0) q.push(i);
    }

    vi order;

    while (q.size()) {
        int u = q.front();
        q.pop();
        order.pb(u);
        for (int v : edges[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (order.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int x : order) {
        cout << x + 1 << " ";
    }
    cout << "\n";
    return 0;
}
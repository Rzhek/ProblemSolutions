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
const int inf = 1e9;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi &B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a])
        if (B[b] == L + 1) {
            B[b] = 0;
            if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
                return btoa[b] = a, 1;
        }
    return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
    int res = 0;
    vi A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        cur.clear();
        for (int a : btoa)
            if (a != -1) A[a] = -1;
        rep(a, 0, sz(g)) if (A[a] == 0) cur.push_back(a);
        for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur)
                for (int b : g[a]) {
                    if (btoa[b] == -1) {
                        B[b] = lay;
                        islast = 1;
                    } else if (btoa[b] != a && !B[b]) {
                        B[b] = lay;
                        next.push_back(btoa[b]);
                    }
                }
            if (islast) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
        }
        rep(a, 0, sz(g)) res += dfs(a, 0, g, btoa, A, B);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vvi edges(n, vi(n, inf));
    forn (i, m) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        edges[u][v] = w;
    }

    forn (i, n) edges[i][i] = 0;
    forn (k, n) forn (i, n) forn (j, n) edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);

    vi startTime(k), from(k), dest(k);
    forn (i, k) {
        cin >> from[i] >> dest[i] >> startTime[i];
        --from[i]; --dest[i];
    }

    vvi g(k);
    vi btoa(k, -1);
    forn (i, k) {
        forn (j, k) {
            if (i != j && startTime[i] + edges[from[i]][dest[i]] + edges[dest[i]][from[j]] <= startTime[j]) {
                g[i].pb(j);
            }
        }
    }

    cout << k - hopcroftKarp(g, btoa) << "\n";

    return 0;
}
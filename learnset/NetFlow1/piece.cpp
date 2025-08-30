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

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    // int isResidual;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, m; cin >> n >> m;
        vector<vector<char>> grid(n + 2, vector<char>(m + 2, '.'));
        map<pii, int> black, even, odd;
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                cin >> grid[r][c];
                if (grid[r][c] == 'B') black[{r, c}] = black.size();
                if (grid[r][c] == 'W' && r % 2 == 0) even[{r, c}] = even.size();
                if (grid[r][c] == 'W' && r % 2 == 1) odd[{r, c}] = odd.size();
            }
        }

        for (auto &it : odd) it.s += even.size();


        int s = even.size() + odd.size();
        int t = s + 1;

        Dinic dinic(s + 2, s, t);

        vector<set<int>> edges(s + 2);

        for (auto [rc, ind] : black) {
            auto [r, c] = rc;
            // cout << r << " " << c << "\n";
            vi myEven, myOdd;
            for (auto [dr, dc] : dirs) {
                if (grid[r+dr][c+dc] != 'W') continue;
                if ((r + dr) % 2 == 0) {
                // cout << "\t1." << r + dr << " " << c + dc << "\n";
                    myEven.push_back(even[{r+dr, c+dc}]);
                } else {
                // cout << "\t2." << r + dr << " " << c + dc << "\n";
                    myOdd.push_back(odd[{r+dr, c+dc}]);
                }
            }

            // cout << myEven.size() << " | " << myOdd.size() << "\n";
            for (auto i : myEven) {
                edges[s].insert(i);
                for (int j : myOdd) {
                    edges[i].insert(j);
                    edges[j].insert(t);
                }
            }

        }

        forn (i, s + 1) {
            for (int j : edges[i]) {
                dinic.add_edge(i, j, 1);
            }
        }

        if (dinic.flow() == even.size() && even.size() == odd.size() && even.size() == black.size()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
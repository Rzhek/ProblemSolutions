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

int n, s, t;
int N;
const int SEGMENTS = 24 * 2;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
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

struct guard {
    int maxTime, good[SEGMENTS];

    guard(int m) : maxTime(m) {
        memset(good, 0, sizeof(good));
    }
};

vector<guard> guards;

int solve(int m) {
    Dinic graph(N, s, t);
    forn (i, n) {
        graph.add_edge(s, i, guards[i].maxTime);
        // cout << i << ": " << guards[i].maxTime << "\n";
        forn (j, SEGMENTS) {
            if (guards[i].good[j]) {
                // cout << "worker " << i << " works at " << j << " time" << "\n"; 
                graph.add_edge(i, n + j, 1);
            } else {
                // cout << "worker " << i << " doesnt work at " << j << " time" << "\n"; 
            }
        }
    }

    forn (j, SEGMENTS) {
        graph.add_edge(n + j, t, m);
    }

    int res = graph.flow();
    // cout << m << ": " << res << "\n"; 
    return res == m * SEGMENTS;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n != 0) {
        N = n + SEGMENTS + 2;
        s = n + SEGMENTS;
        t = s + 1;
        forn (i, n) {
            int k, m; cin >> k >> m;
            guard g(m / 30);
            int good[24*60]{};
            forn (j, k) {
                string tmp; cin >> tmp;
                int t1 = stoi(tmp.substr(0, 2));
                int m1 = stoi(tmp.substr(3, 2));
                m1 += 60 * t1;
                
                cin >> tmp;
                int t2 = stoi(tmp.substr(0, 2));
                int m2 = stoi(tmp.substr(3, 2));
                m2 += 60 * t2;

                if (m2 <= m1) m2 += 24 * 60;
                for (; m1 < m2; m1++) {
                    good[m1%(24*60)] = 1;
                }

                
            }
            forn (seg, SEGMENTS) {
                int isGood = 1;
                for (int a = seg * 30; isGood && a < (seg + 1) * 30; a++) isGood &= good[a];

                // cout << seg << "\n";
                if (isGood) g.good[seg] = 1;
            }
            guards.push_back(g);
        }

        // for (auto &g : guards) {
        //     printArr(g.good);
        // }

        // int res = 0;
        // for (; res <= n && solve(res); res++) {}
        // cout << res - 1 << "\n";


        int lo = 0, hi = n;
        int res = 0;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (solve(m)) {
                res = m;
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }
        cout << res << "\n";
        guards.clear();
        cin >> n;

    }
    return 0;
}
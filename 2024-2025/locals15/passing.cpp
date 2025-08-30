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
const int inf = 1e9;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

struct Edge {
    int i, j, cap, flow, carry;
    Edge *rev;

    Edge (int ii, int jj, int cc, int ff) {
        i = ii;
        j = jj;
        cap = cc;
        flow = ff;
    }
};

struct Flow {
    vector<Edge> stk;
    int N, fptr, bptr, s, t;
    vector<vector<Edge>> adjj, adj;
    vi q, dist, pool;

    Flow (int NN) {
        N = (t = (s = NN) + 1) + 1;
        adjj = vector<vector<Edge>>(N);
        adj = vector<vector<Edge>>(N);
        dist = vi(N);
        pool = vi(N);
        q = vi(N);
    }

    void add(int i, int j, int cap, bool directed) {
        // Edge * fwd = new Edge(i, j, cap, 0);
        // Edge * rev = new Edge(j, i, 0, directed ? 0 : -cap);
        // rev->rev = fwd;
        // fwd->rev = rev;
        // adjj[i].push_back(*fwd);
        Edge fwd(i, j, cap, 0);
        Edge rev(j, i, 0, directed ? 0 : -cap);
        rev.rev = &fwd;
        fwd.rev = &rev;
        adjj[i].push_back(fwd);
        adjj[j].push_back(rev);
    }

    int augment() {
        fill(all(dist), inf);
        pool[t] = dist[s] = fptr = bptr = 0;
        pool[q[bptr++] = s] = inf;
        while (bptr > fptr && q[fptr] != t) {
            for (Edge e : adj[q[fptr++]]) {
                if (dist[e.i] < dist[e.j])
                    pool[e.j] += e.carry = min(e.cap - e.flow, pool[e.i]);
                if (dist[e.i] + 1 < dist[e.j] && e.cap > e.flow)
                    dist[q[bptr++] = e.j] = dist[e.i] + 1;
            }
        }
        if (pool[t] == 0) return 0;
        fill(all(pool), fptr = bptr = 0);
        pool[q[bptr++] = t] = inf;
        while (bptr > fptr) {
            for (Edge e : adj[q[fptr++]]) {
                if (pool[e.i] == 0) break;
                int f = e.rev->carry = min(pool[e.i], e.rev->carry);
                if (dist[e.i] > dist[e.j] && f != 0) {
                    if (pool[e.j] == 0)
                        q[bptr++] = e.j;
                    pool[e.i] -= f;
                    pool[e.j] += f;
                    stk.push_back(*e.rev);
                }
            }
        }
        int res = pool[s];
        fill(all(pool), 0);
        pool[s] = res;
        while (stk.size()) {
            Edge e = stk.back();
            stk.pop_back();
            int f = min(e.carry, pool[e.i]);
            pool[e.i] -= f;
            pool[e.j] += f;
            e.flow += f;
            e.rev->flow -= f;
        }
        return res;
    }
    int getFlow() {
        int res = 0, f = 1;
        for (int i = 0; i < N; i++) {
            adj[i] = adjj[i];
        }
        while (f != 0) {
            res += f = augment();
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        int total = 0;
        Flow graph(n);
        for (int k = 0; k < n; k++) {
            double w; cin >> w;
            int weight = w * 100;
            total += weight;
            graph.add(graph.s, k, weight, true);
        }
        for (int k = 0; k < n; k++) {
            double w; cin >> w;
            int weight = w * 100;
            total += weight;
            graph.add(k, graph.t, weight, true);
        }

        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                double w; cin >> w;
                int weight = w * 100;
                total += weight;
                graph.add(k, j, weight, false);
            }
        }

        int ans = total - graph.getFlow();

        cout << total / 100.0 << "\n";
    }
    return 0;
}
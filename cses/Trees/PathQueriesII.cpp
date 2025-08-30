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
const int MOD = 1e9+7;
const int mod2inv = 500000004;
const long double EPS = 1e-9;

struct Node {
    int n;
    vector<int> tree;

    Node(int l, int n) : n(n), tree(4 * n, -1e9) {}

    void set(int idx, int l, int r, int pos, int val) {
        if (l + 1 == r) {
            tree[idx] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos < m)
            set(2 * idx + 1, l, m, pos, val);
        else
            set(2 * idx + 2, m, r, pos, val);
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    int query(int idx, int l, int r, int lo, int hi) {
        if (hi <= l || lo >= r) return -1e9;
        if (lo <= l && r <= hi) return tree[idx];
        int m = (l + r) / 2;
        return max(query(2 * idx + 1, l, m, lo, hi),
                   query(2 * idx + 2, m, r, lo, hi));
    }

    void set(int pos, int val) {
        set(0, 0, n, pos, val);
    }

    int query(int lo, int hi) {
        return query(0, 0, n, lo, hi);
    }
};

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

int query(int a, int b, Node *ST) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = ST->query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = ST->query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;

    vi nums(n);
    forn (i, n) cin >> nums[i];
    vector<vi> adj(n);
    forn (i, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    init(adj);
    Node *ST = new Node(0, n);

    for (int i = 0; i < n; i++) ST->set(pos[i], nums[i]);


    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            int u, x; cin >> u >> x;
            --u;
            ST->set(pos[u], x);
        } else {
            int u, v; cin >> u >> v;
            --u; --v;
            cout << query(u, v, ST) << " ";
        }
    }
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5+5;
int n, q, timer = 0, in[maxn], out[maxn], nums[maxn];
vector<int> adj[maxn];

struct Node {
    int l, r, m;
    ll val, prop;
    Node *left, *right;

    Node(int l, int r, ll val = 0) : l(l), r(r), m((l+r)/2), val(val), prop(0) {
        if (l + 1 == r) left = right = nullptr;
        else left = new Node(l, m), right = new Node(m, r);
    }

    void update(int lo, int hi, ll v) {
        if (lo >= r || hi <= l) {
            return;
        }
        if (lo <= l && r <= hi) {
            prop += v;
            return;
        }

        val += prop;
        left->prop += prop;
        right->prop += prop;
        prop = 0;

        left->update(lo, hi, v);
        right->update(lo, hi, v);
    }  

    ll query(int idx) {
        if (l + 1 == r) {
            assert(l == idx);
            return val + prop;
        }
        val += prop;
        left->prop += prop;
        right->prop += prop;
        prop = 0;

        if (idx < m) return left->query(idx);
        return right->query(idx);
    }

};

void dfs(int u, int p = -1) {
    in[u] = timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        timer++;
        dfs(v, u);
    }
    out[u] = timer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    Node ST(0, n+1);
    for (int i = 0; i < n; i++) cin >> nums[i];

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);
    for (int i = 0; i < n; i++) {
        ST.update(in[i], out[i] + 1, nums[i]);
    }

    while (q--) {
        int type, u; cin >> type >> u;
        u--;
        if (type == 1) {
            int x; cin >> x;
            ST.update(in[u], out[u] + 1, x - nums[u]);
            nums[u] = x;
        } else {
            cout << ST.query(in[u]) << "\n";
        }
    }
}
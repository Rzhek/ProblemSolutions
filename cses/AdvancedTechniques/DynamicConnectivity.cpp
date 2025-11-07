#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

using vi = vector<int>;
using pii = pair<int, int>;

struct RollbackUF {
    vi e, delta; vector<pii> st;
    int numcomp;

    RollbackUF(int n) : e(n, -1), numcomp(n) {}

    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }

    void rollback(int t) {
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second, numcomp -= delta[i];
        st.resize(t);
        delta.resize(t);
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        delta.push_back(-1);
        delta.push_back(0);
        numcomp--;
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

struct Node {
    int lo, hi, m, t;
    Node *left, *right;
    vector<pii> edges;

    Node(int lo, int hi): lo(lo), hi(hi), m((lo+hi)/2), t(-1) {
        if (lo + 1 == hi) {
            left = right = nullptr;
        } else {
            left = new Node(lo, m);
            right = new Node(m, hi);
        }
    }

    // adds an edge to completely cover [l, r) range
    void addEdge(int l, int r, int u, int v) {
        if (l >= r || r <= lo || hi <= l) return;
        if (l <= lo && hi <= r) {
            edges.push_back({u, v});
            return;
        }
        left->addEdge(l, r, u, v);
        right->addEdge(l, r, u, v);
    }

    void walk(RollbackUF &dsu, vector<int> &res) {
        t = dsu.time();
        for (auto [u, v] : edges) dsu.join(u, v);
        dsu.print();
        // cout << "\n";
        if (lo + 1 == hi) {
            res[lo] = dsu.numcomp;
        } else {
            left->walk(dsu, res);
            right->walk(dsu, res);
        }
        dsu.rollback(t);
    }

};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    Node ST(0, k);
    map<pii, int> start; 
    RollbackUF dsu(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        start[{u, v}] = 0;
        dsu.join(u, v);
    }

    int f = dsu.numcomp;
    dsu = RollbackUF(n);
    vi res(k);


    for (int i = 0; i < k; i++) {
        int type, u, v; cin >> type >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        if (type == 1) {
            start[{u, v}] = i;
        } else {
            ST.addEdge(start[{u, v}], i, u, v);
            start.erase({u, v});
        }
    }
    for (auto [e, s] : start) {
        auto [u, v] = e;
        ST.addEdge(s, k, u, v);
    }

    ST.walk(dsu, res);
    cout << f << " ";
    for (int i = 0; i < k; i++) cout << res[i] << " ";
    cout << "\n";
}
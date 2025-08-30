#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937 gen(rand());
uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

struct node {
    int pri, sz = 1, rev = 0;
    ll val, sum;
    node *l = NULL, *r = NULL;
    node(ll v): val(v), sum(v) { pri = dist(gen); }
};
int getSz(node *in) { return in ? in->sz : 0; }
ll getSum(node *in) { return in ? in->sum : 0; }
    
void push(node *in) {
    if (in->rev) {
        swap(in->l, in->r);
        if (in->l) in->l->rev ^= 1;
        if (in->r) in->r->rev ^= 1;
        in->rev = 0;
    }
}

void pull(node *in) {
    in->sz = getSz(in->l) + 1 + getSz(in->r);
    in->sum = getSum(in->l) + in->val + getSum(in->r);
}

pair<node *, node *> split(node *in, int leftIdx) {
    if (!in) return {NULL, NULL};
    push(in);
    if (leftIdx < getSz(in->l)) {
        auto [lLeft, lRight] = split(in->l, leftIdx);
        in->l = lRight;
        pull(in);
        return {lLeft, in};
    }
    auto [rLeft, rRight] = split(in->r, leftIdx - (getSz(in->l) + 1));
    in->r = rLeft;
    pull(in);
    return {in, rRight};
}

node *merge(node *a, node *b) {
    if (!a) return b;
    if (!b) return a;
    push(a), push(b);
    if (a->pri < b->pri) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    b->l = merge(a, b->l);
    pull(b);
    return b;
}
    
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    node *treap = NULL;

    while (n--) {
        int x; cin >> x;
        treap = merge(treap, new node(x));
    }

    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            auto [a, bc] = split(treap, l - 2);
            auto [b, c] = split(bc, r - l);

            b->rev ^= 1;
            treap = merge(a, merge(b, c)); 
        } else {
            auto [a, bc] = split(treap, l - 2);
            auto [b, c] = split(bc, r - l);
            
            cout << getSum(b) << "\n";
            treap = merge(a, merge(b, c)); 
        }
    }
}
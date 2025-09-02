#include <bits/stdc++.h>
using namespace std;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(INT_MIN, INT_MAX);

struct node {
    int pri, sz = 1, rev = 0;
    char val;
    node *l = NULL, *r = NULL;
    node (char v): val(v) {pri = distrib(gen); }
};

int getSz(node *in) { return in ? in->sz : 0; }
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

void print(node * a) {
    if (!a) return;
    push(a);
    print(a->l);
    cout << a->val;
    print(a->r); 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    node *treap = NULL;
    while (n--) {
        char ch; cin >> ch;
        treap = merge(treap, new node(ch));
    }

    while (q--) {
        int l, r; cin >> l >> r;
        auto [a, bc] = split(treap, l - 2);
        auto [b, c] = split(bc, r - l);
        if (b) b->rev ^= 1;
        // print(a); cout << "\n";
        // print(b); cout << "\n";
        // // print(c); cout << "\n";
        treap = merge(merge(a, b), c);
        // print(treap); cout << "\n\n";
    }

    print(treap);
    cout << "\n";
}
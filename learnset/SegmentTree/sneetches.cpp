#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

struct Node {
    Node *left, *right;
    int l, r, m;
    int pref1, suf1, best1;
    int pref2, suf2, best2;
    int prop;

    Node(vi &nums, int l, int r) : l(l), r(r), m((l+r)/2), prop(0) {
        if (l + 1 == r) {
            pref1 = suf1 = best1 = nums[m];
            pref2 = suf2 = best2 = !nums[m];
            left = right = nullptr;
            return;
        }
        left = new Node(nums, l, m);
        right = new Node(nums, m, r);
        calc();
    }

    void calc() {
        left->apply();
        right->apply();
        pref1 = left->pref1 == (m - l) ? left->pref1 + right->pref1 : left->pref1;
        suf1 = right->suf1 == (r - m) ? left->suf1 + right->suf1 : right->suf1;
        best1 = max({left->best1, right->best1, left->suf1 + right->pref1});

        pref2 = left->pref2 == (m - l) ? left->pref2 + right->pref2 : left->pref2;
        suf2 = right->suf2 == (r - m) ? left->suf2 + right->suf2 : right->suf2;
        best2 = max({left->best2, right->best2, left->suf2 + right->pref2});
    }

    void push() {
        if (!left) return;
        left->prop ^= prop;
        right->prop ^= prop;
    }

    void apply() {
        if (!prop) return;
        push();
        swap(pref1, pref2);
        swap(suf1, suf2);
        swap(best1, best2);
        prop = 0;
    }

    void update(int lo, int hi) {
        if (lo >= r || hi <= l) return;
        if (lo <= l && r <= hi) {
            prop ^= 1;
            apply();
            return;
        }

        assert(l + 1 != r); // can't have partial overlap on an interval of length 1
        apply();
        left->update(lo, hi);
        right->update(lo, hi);
        calc();
    }
};

void printNode(Node *node) {
    cout << "[" << node->l << " " << node->r << ") " << "{" << node->prop << "}: ";
    cout << node->pref1 << " " << node->suf1 << " " << node->best1 << " | ";
    cout << node->pref2 << " " << node->suf2 << " " << node->best2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vi nums(n);
        for (int i = 0; i < n; i++) {
            char ch; cin >> ch;
            nums[i] = ch == 'S';
        }
        Node ST(nums, 0, n);

        while (q--) {
            int a, b; cin >> a >> b;
            ST.update(a-1, b);
            cout << ST.best1 << " " << ST.best2 << "\n";
        }
    }
    return 0;
}
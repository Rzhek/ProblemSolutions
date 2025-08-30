#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct Node Node;

struct Node {
    int l, h, m;
    ll val;
    Node * left, * right;

    Node(int l, int h) {
        this->l = l;
        this->h = h;
        this->m = (l + h) / 2;
        this->val = 0;
        if (l != h) {
            this->left = new Node(l, m);
            this->left = new Node(m + 1, h);
        } else {
            this->left = this->right = nullptr;
        }
    }

    ll set(vector<int> arr) {
        if (this->l == this->h) {
            this->val = arr[this->l];
        } else {
            this->left->set(arr);
            this->right->set(arr);
            this->val = this->left->val + this->right->val;
        }
    }

    ll query(int lo, int hi) {
        // No over
        if (hi < this->l || this->h < lo) {
            return 0;
        }

        // Total over
        if (lo <= this->l && this->l <= this->h && this->h <= hi) {
            return this->val;
        }

        // Partial over
        return this->left->query(lo, hi) + this->right->query(lo, hi);

    }
};

int main() {
    int n, q, num, l, h; cin >> n >> q;
    Node SegTree = Node(1, n);
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    SegTree.set(arr);

    for (int i = 0; i < q; i++) {
        cin >> l >> h;
        cout << SegTree.query(l, h) << endl;
    }

    return 0;
}
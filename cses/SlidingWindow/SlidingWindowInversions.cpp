#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    int lo, hi, m, val;
    Node *left, *right;

    Node(int lo, int hi): lo(lo), hi(hi), m((lo+hi)/2), val(0) {
        left = right = nullptr;
    }

    void add(int i, int v) {
        if (lo + 1 == hi) {
            val += v;
            return;
        }

        if (!left) left = new Node(lo, m);
        if (!right) right = new Node(m, hi);

        if (i < m) left->add(i, v);
        else right->add(i, v);
        val = left->val + right->val;
    }

    int query(int l, int r) {
        if (l <= lo && hi <= r) return val;
        if (hi <= l || r <= lo) return 0;

        if (!left) left = new Node(lo, m);
        if (!right) right = new Node(m, hi);

        return left->query(l, r) + right->query(l, r);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    Node ST(0, 1e9+10);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ST.add(nums[i], 1);
        res += ST.query(nums[i] + 1, 1e9+9);

        if (i >= k - 1) {
            ST.add(nums[i-k+1], -1);
            cout << res << " ";
            res -= ST.query(0, nums[i-k+1]);
        }
    }
    cout << "\n";
}
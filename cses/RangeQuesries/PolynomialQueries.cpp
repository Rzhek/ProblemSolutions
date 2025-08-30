#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Prop represents that the whole interval [l,r) should be increased
// The first element should be increased by prop, the 2nd by prop + 1, and so on
// prop of 0 indicates no increment

struct Node {
    ll l, r, m, len, val, stat = 0, step = 0;
    Node *left, *right;

    Node(vector<int> &nums, int l, int r) : l(l), r(r), m((l+r)/2), len(r-l) {
        if (l + 1 == r) {
            val = nums[l];
            left = right = 0;
        } else {
            left = new Node(nums, l, m);
            right = new Node(nums, m, r);
            val = left->val + right->val;
        }
    }

    ll get() {
        return val + stat * len + step * len * (len + 1) / 2;
    }

    void apply() {
        if (stat == 0 && step == 0) return;
        if (l + 1 != r) {
            left->stat += stat;
            right->stat += stat + (m - l) * step;
            left->step += step;
            right->step += step;

            // val += stat * len + step * len * (len - 1) / 2;
        } 
        val = get();
        stat = step = 0;
    }

    void update(int lo, int hi) {
        apply();
        if (lo >= r || hi <= l) {
            return;
        }
        if (lo <= l && r <= hi) {
            stat += l - lo;
            step++;
            apply();
            return;
        }
        
        left->update(lo, hi);
        right->update(lo, hi);
        val = left->get() + right->get();
    }
    
    ll query(int lo, int hi) {
        apply();
        if (lo >= r || hi <= l) return 0;
        if (lo <= l && r <= hi) {
            return get();
        }
        return left->query(lo, hi) + right->query(lo, hi);
    }

    void check() {
        if (!left) return;
        ll a = get();
        // apply();
        if (val != left->get() + right->get()) {
            cout << "@ node " << l << " " << r << " with (" << val << "," << stat << ", " << step << ")\n";
            cout << "left: " <<  left->l << " " << left->r << " with (" << left->val << "," << left->stat << ", " << left->step << ")\n";
            cout << "right: " <<  right->l << " " << right->r << " with (" << right->val << "," << right->stat << ", " << right->step << ")\n";
        }
        left->check();
        right->check();
    }

    void fullApply() {
        apply();
        if (!left) return;
        left->fullApply();
        right->fullApply();
    }

    void print() {
        cout << "(" << l << ", " << r << ") -> val(" << val << "), prop(" << stat << " " << step << ")\n"; 
        if (left) {
            left->print();
            right->print();
        }
    }
};

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    Node *ST = new Node(nums, 0, n);

    while (q--) {
        int type; cin >> type;
        int a, b; cin >> a >> b;
        if (type == 1) {
            ST->update(a-1, b);
            // ST->fullApply();
        } else {
            cout << ST->query(a-1, b) << "\n";
        }
        // ST->check();
        // cout << "==========================\n";
    }
}
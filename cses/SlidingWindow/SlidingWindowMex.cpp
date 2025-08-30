#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, m, val, filled;
    Node *lo, *hi;

    Node (int l, int r): l(l), r(r), m((l + r) / 2), val(0), filled(0) {
        lo = hi = nullptr;
    }

    int len() const { return r - l; }

    void update(int i, int v) {
        if (l + 1 == r) {
            val += v;
            filled = val > 0;
            return;
        }
        if (lo == nullptr) lo = new Node(l, m);
        if (hi == nullptr) hi = new Node(m, r);

        if (i < m) lo->update(i, v);
        else hi->update(i, v);
        filled = lo->filled && hi->filled;
    }

    int mex() {
        if (!lo) return l;
        if (!lo->filled) return lo->mex();
        if (!hi) return m;
        return hi->mex();
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    Node ST(0, 1e9+5);

    for (int i = 0; i < n; i++) {
        ST.update(nums[i], 1);

        if (i >= k - 1) {
            cout << ST.mex() << " ";
            ST.update(nums[i-k+1], -1);
        }
    }
    cout << "\n";
}
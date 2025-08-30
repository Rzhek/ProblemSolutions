#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

void binSearch() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> res;
    for (int num : nums) {
        if (res.size() == 0) {
            res.push_back(num);
            continue;
        }
        auto it = lower_bound(res.begin(), res.end(), num);
        if (it == res.end()) {
            res.push_back(num);
        } else {
            *it = num;
        }
    }
    cout << res.size() << '\n';
}

struct ST {
    int n;
    vector<int> tree;

    ST(int _n) : n(_n) {
        tree.resize(4*n, 0);
    }

    void update(int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree[i] = val;
            return;
        }

        int m = (l + r) >> 1;
        if (m >= ind) update(ind, val, l, m, i * 2 + 1);
        else update(ind, val, m + 1, r, i*2+2);

        tree[i] = max(tree[i*2+1], tree[i*2+2]);
    }

    int query(int x, int y, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree[i];

        int m = (l+r) >> 1;
        return max(
            query(x, y, l, m, i*2+1),
            query(x, y, m+1, r, i*2+2)
        );
    }
};

void segTree() {
    int n; cin >> n;
    vector<int> nums(n), res(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<pii> val_and_ind;
    for (int j = 0; j < n; j++) val_and_ind.push_back({nums[j], j});
    sort(val_and_ind.begin(), val_and_ind.end());

    // for (auto x : val_and_ind) cout << x.first << " ";
    // cout << '\n';
    // for (auto x : val_and_ind) cout << x.second << " ";
    // cout << '\n';
    

    map<int, int> position;
    for (int j = 0; j < n; j++) {
        position[val_and_ind[j].second] = j;
    }

    // for (auto &[x, y] : position) {
    //     cout << x << " ";
    // }
    // cout << '\n';
    // for (auto &[x, y] : position) {
    //     cout << y << " ";
    // }
    // cout << '\n';

    ST tree(n);
    for (int j = 0; j < n; j++) {
        int lb = lower_bound(val_and_ind.begin(), val_and_ind.end(), make_pair(nums[j], -1)) - val_and_ind.begin();
        int val = 1 + (lb > 0 ? tree.query(0, lb-1, 0, n - 1, 0) : 0);
        tree.update(position[j], val, 0, n-1, 0);
    }
    cout << tree.query(0, n-1, 0, n-1, 0) << '\n';
}

int main() {
    // binSearch();
    segTree();
}
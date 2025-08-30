#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *left, *right;
    int val, lvl;

    Node() : left(nullptr), right(nullptr), val(0), lvl(0) {}

    void init(vector<int> &nums, int l, int r, int lvl) {
        if (lvl < 0) return;
        this->left = new Node();
        int m = l + (r - l) / 2;
        this->left->init(nums, l, m, lvl - 1);
        this->right = new Node();
        this->right->init(nums, m, r, lvl - 1);
        this->lvl = lvl;
        if (lvl == 0) {
            this->val = nums[l];
        } else if (lvl % 2 != 0) {
            this->val = this->left->val | this->right->val;
        } else {
            this->val = this->left->val ^ this->right->val;
        }
    }

    void update(int ind, int val, int l, int r) {
        int m = l + (r - l) / 2;
        // cout << this->lvl << " " << l << " " << m << " " << r << '\n';
        if (ind < m) {
            // cout << "LEFT\n";
            this->left->update(ind, val, l, m);
        } else if (ind >= m && this->lvl != 0) {
            // cout << "RIGHT\n";
            this->right->update(ind, val, m, r);
        } else {
            this->val = val;
        }
        if (this->lvl > 0) {
            if (this->lvl % 2 != 0) {
                this->val = this->left->val | this->right->val;
            } else {
                this->val = this->left->val ^ this->right->val;
            }
        }
    }

};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Node * ST = new Node();
    int n, m; cin >> n >> m;
    vector<int> nums((1 << n));
    for (int i = 0; i < (1 << n); i++) cin >> nums[i];
    ST->init(nums, 0, (1 << n), n);

    for (int i = 0; i < m; i++) {
        int ind, newVal; cin >> ind >> newVal;
        ST->update(ind-1, newVal, 0, (1 << n));
        cout << ST->val << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int l, int r) {
    // cout << l << " " << r << "\n";
    if (l == r - 1) return;
    int m = (l + r) / 2;
    solve(nums, l, m);
    solve(nums, m, r);

    for (int i = l; i < m; i++) {
        swap(nums[i], nums[i + m - l]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> nums(1 << n);
    for (auto &x : nums) cin >> x;

    if (k % 2) solve(nums, 0, 1 << n);

    for (int x : nums) cout << x << " ";
    cout << "\n";

}
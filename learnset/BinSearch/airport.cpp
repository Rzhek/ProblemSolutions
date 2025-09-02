#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums, int t, int k) {
    int last = *nums.begin();
    for (auto x : nums) {
        if (x - last > t) {
            k--;
            last = x;
        }
        if (k <= 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;
    sort(nums.begin(), nums.end());

    int lo = 0, hi = 1e9+10;
    // hi always works

    while ((hi - lo) > 1) {
        int m = (lo + hi) / 2;
        if (solve(nums, m, k)) {
            hi = m;
        } else {
            lo = m;
        }
    }
    if (solve(nums, lo, k)) hi = lo;

    cout << hi << "\n";
}
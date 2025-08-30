#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(vector<int> &nums, int m) {
    int res = 0;
    for (auto x : nums) {
        res += abs(x - m++);
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int lo = -5e5-10, hi = 5e5+10;
    int res = 1e18;
    while (lo < hi) {
        int m_lo = (2 * lo + hi) / 3, m_hi = (lo + 2 * hi + 1) / 3;
        int res_lo = solve(nums, m_lo);
        int res_hi = solve(nums, m_hi);
        res = min({res, res_lo, res_hi});
        if (res_lo <= res_hi) {
            hi = m_hi - 1;
        } else {
            lo = m_lo + 1;
        }
    }
    cout << res << "\n";
}
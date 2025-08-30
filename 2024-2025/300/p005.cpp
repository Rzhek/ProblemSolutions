#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, c; cin >> n >> c;
    vector<int> nums(n), sums(n);
    for (auto &x : nums) cin >> x;
    sort(nums.begin(), nums.end());
    partial_sum(nums.begin(), nums.end(), sums.begin());

    bitset<maxn> dp;
    dp[0] = dp[maxn-1] = 1;

    int res = sums.back();
    for (int i = n - 1; i + 1; --i) {
        int prefix = sums[i];
        for (int j = max(0, c - prefix + 1); j <= min(maxn-1, c - prefix + nums[i]); j++) {
            if (dp[j]) {
                res = min(res, prefix + j - nums[i]);
            }
        }

        dp |= dp << nums[i];
    }

    cout << res << "\n";
}
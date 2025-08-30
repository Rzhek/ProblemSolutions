#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi nums(n);
    vector<vi> dp(2, vi(1 << n, 1e9)); // cloack pos, mask
    for (auto &x : nums) cin >> x;

    auto solve = [&](int mask, int pos, auto &solve) -> int {
        if (mask == 0 && pos == 1) return 0;
        auto &res = dp[pos][mask];
        if (res != 1e9) return res;
        
        if (pos == 0) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) continue;
                for (int j = i + 1; j < n; j++) {
                    if ((mask & (1 << j)) == 0) continue;
                    int new_mask = mask - (1 << i) - (1 << j);
                    res = min(res, max(nums[i], nums[j]) + solve(new_mask, 1, solve));
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                int new_mask = mask + (1 << i);
                res = min(res, nums[i] + solve(new_mask, 0, solve));
            }
        }
        return res;
    };
    cout << solve((1 << n) - 1, 0, solve) << "\n";
}
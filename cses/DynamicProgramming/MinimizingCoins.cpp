#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vi nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    vi dp(x + 1, 1e8);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); ++i) {
        for (int j : nums) {
            if (i - j < 0) break;
            dp[i] = min(dp[i], dp[i-j] + 1);
        }
    }
    cout << (dp.back() < 1e8 ? dp.back() : -1) << '\n';

    return 0;
}
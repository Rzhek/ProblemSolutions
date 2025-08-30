#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int mod = 1e9+7;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<ll> nums(n), dp(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] <= x) dp[nums[i]] = 1;
    }
    sort(nums.begin(), nums.end());
 
    for (int i = 1; i <= x; ++i) {
        if (!dp[i]) continue;
        for (auto j : nums) {
            if (i + j > x) break;
            dp[i+j] += dp[i];
            dp[i+j] %= mod;
        }
    }
 
 
    cout << dp.back() << '\n';
 
 
    return 0;
}
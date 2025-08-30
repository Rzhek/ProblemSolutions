#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<ll> nums(n), dp(x + 1, 0); dp[0] = 1;
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    for (int coin = 0; coin < n; coin++) {
        for (int i = 0; i <= x; i++) {
            if (dp[i] && (i + nums[coin] <= x)) {
                dp[i + nums[coin]] += dp[i];
                dp[i + nums[coin]] %= MOD;
            }
        }
    }

    
    
    cout << dp.back() << '\n';
    return 0;
}
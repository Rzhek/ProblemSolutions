#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vl nums(n), dp;
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n;) {
        // int cur = nums[i];
        // cout << i << '\n';
        int length = 0;
        int j = i;
        for (; j < n && nums[i] == nums[j]; j++) {
            length++;
        }
        dp.push_back(length * nums[i]);
        if (j < n && nums[j] != nums[i] + 1) {
            dp.push_back(0);
        }
        i = j;
    }
    if (dp.size() == 0) {
        cout << dp.back() << '\n';
        return 0;
    }
    vl res(dp.size(), 0);
    res[0] = dp[0];
    res[1] = max(dp[0], dp[1]);
    for (int i = 2; i < res.size(); i++) {
        res[i] = max(res[i-2] + dp[i], res[i-1]);
    }
    
    cout << res.back() << '\n';

    return 0;
}
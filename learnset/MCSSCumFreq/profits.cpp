#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (1) {
        int n; cin >> n;
        if (!n) break;
        vector<int> nums(n + 1); nums[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> nums[i]; 
            nums[i] += nums[i-1];
        }
        int curMin = 0;
        int res = -1e9;
        for (int i = 1; i <= n; i++) {
            res = max(res, nums[i] - nums[curMin]);
            if (nums[i] < nums[curMin]) curMin = i;
        }
        cout << res << '\n';
    }
    return 0;
}
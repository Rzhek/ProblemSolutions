#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[i] -= a;
    }
    sort(nums.begin(), nums.end());
    ll res = 0;
    for (int i = 0; i < n - 1; i++) {
        int required;
        if (nums[i] <= 0) {
            required = -nums[i];
        } else {
            required = 0;
        }
        auto first = upper_bound(nums.begin() + i + 1, nums.end(), required);
        res += distance(first, nums.end());
    }

    cout << res << '\n';
    return 0;
}
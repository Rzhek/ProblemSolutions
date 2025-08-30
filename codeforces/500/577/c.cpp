#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    nums.push_back(2e9);

    int val = nums[n/2];
    for (int i = n/2; i < n; i++) {
        while (val == nums[i+1]) i++;
        int canRaise = k / (i - n/2 + 1);
        if (canRaise >= nums[i+1] - val) {
            k -= (nums[i+1] - val) * (i - n/2 + 1);
            val = nums[i+1];
        } else {
            val += canRaise;
            break;
        }
    }

    cout << val << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int med = nums[n / 2];
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(nums[i] - med);
    }

    cout << res << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cnt[nums[i]]++;
        if (i >= k - 1) {
            cout << cnt.size() << " ";
            if (--cnt[nums[i-k+1]] == 0) cnt.erase(nums[i-k+1]);
        }
    }
}
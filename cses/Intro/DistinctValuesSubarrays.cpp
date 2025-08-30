#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    map<int, int> pos;
    // [l, r]
    int l = 0;
    ll res = 0;
    for (int r = 0; r < n; r++) {
        if (pos.count(nums[r]))  {
            for (; l <= pos[nums[r]]; l++) pos.erase(nums[l]);
        }
        res += (r - l + 1);
        pos[nums[r]] = r;
    }
    cout << res << "\n";
}
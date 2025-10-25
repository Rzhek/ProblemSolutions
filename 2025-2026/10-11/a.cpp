#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> nums(n);

    for (auto &x : nums) cin >> x;

    int l = 0, r = n - 1;
    int res = 0;
    while (l < r) {
        if (nums[l] < nums[r]) {
            nums[l+1] += nums[l];
            l++;
            res++;
        } else if (nums[l] > nums[r]) {
            nums[r-1] += nums[r];
            r--;
            res++;
        } else {
            l++; r--;
        }
    }
    cout <<res << "\n";
}
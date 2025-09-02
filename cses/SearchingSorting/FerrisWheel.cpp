#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int lo = 0, hi = n - 1;
    int res = 0;
    while (lo < hi) {
        if (nums[lo] + nums[hi] <= x) {
            lo++; hi--;
            res++;
        } else {
            hi--;
            res++;
        }
    }
    
    cout << res + (lo == hi) << '\n';

    return 0;
}
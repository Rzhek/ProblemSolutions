#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;
    sort(nums.begin(), nums.end());

    ll sum = 0, sum2 = 0;
    ld res = 1e18;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        sum2 += nums[i] * (ll)nums[i];

        if (i >= k - 1) {
            ld mean = (ld)sum / k;
            ld tmp = sum2 - 2 * mean * sum + k * mean * mean;
            res = min(res, tmp);

            sum -= nums[i-k+1];
            sum2 -= nums[i-k+1] * (ll)nums[i-k+1];
        }
    }
    cout << fixed << setprecision(6) << res << "\n";
}
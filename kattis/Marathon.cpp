#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e6;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    double worst = max(nums[0], maxn-nums.back());
    for (int i = 1; i < n; i++) worst = max(worst, (nums[i]-nums[i-1]) / 2.0);

    int lastStation = -1;
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (lastStation == -1) {
            if (nums[i+1] > worst) lastStation = nums[i];
            else ans++;
        } else {
            if ((nums[i+1]-lastStation) / 2.0 > worst) lastStation = nums[i];
            else ans++;
        }
    }

    if (maxn-lastStation <= worst) ans++;

    cout << fixed << setprecision(1) << worst << " " << ans << "\n"; 

}
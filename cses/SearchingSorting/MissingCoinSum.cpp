#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> nums(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        if (nums[i] - cur > 1) {
            cout << cur + 1 << '\n';
            return 0;
        }
        cur += nums[i];
    }

    cout << cur + 1 << '\n';


    return 0;
}
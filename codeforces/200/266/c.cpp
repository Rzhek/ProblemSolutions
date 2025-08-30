#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (i > 0) nums[i] += nums[i-1]; 
    }
    if (nums.back() % 3 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    ll third = nums.back() / 3;

    ll res = 0;
    ll seen = 0;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == third * 2) {
            res += seen;
        }
        if (nums[i] == third) {
            seen++;
        }
    }

    cout << res << '\n';
    return 0;
}
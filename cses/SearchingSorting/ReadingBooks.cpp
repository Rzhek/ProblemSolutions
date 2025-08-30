#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> nums(n);
    ll total = 0, largest = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        total += nums[i];
        largest = max(largest, nums[i]);
    }
    cout << (largest > total - largest ? largest * 2 : total) << '\n';
    return 0;
}
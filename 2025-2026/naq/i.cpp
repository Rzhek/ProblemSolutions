#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums1(n), nums2(n);
    for (auto &x : nums1) cin >> x;
    for (auto &x : nums2) cin >> x;

    sort(nums2.begin(), nums2.end());
    reverse(nums2.begin(), nums2.end());

    ld best = 0;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += nums2[i];
        best = max(best, (ld)(cur + nums1[i]) / (i + 1));
    }
    cout << fixed << setprecision(10) << best << "\n";
}
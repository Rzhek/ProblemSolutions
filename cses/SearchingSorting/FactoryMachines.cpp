#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

int test(vl &nums, ll t, ll k) {
    // cout << k << '\n';
    for (ll num : nums) {
        // cout << k << " " << t << " " << num << " " << t / num << '\n';
        // cout << k << " " << t << " " << num << "->>>";
        // cout << t / num << '\n';
        k -= t / num;
        // cout << k << '\n';
        if (k <= 0) {
            // cout << "return\n";
            return 1;
        }
        // cout << k << '\n';
    }
    // cout << "return";
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vl nums(n);
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        total += nums[i];
    }
    ll lo = 1, hi = LLONG_MAX;
    // cout << hi << '\n';
    // cout << test(nums, 5000, k) << '\n';
    while (lo < hi) {
        ll m = (ll)(((unsigned ll)lo + hi) / 2);
        // cout << lo << " " << hi << " " << m << '\n';
        if (test(nums, m, k)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }

    cout << (lo + hi) / 2 << '\n';
    return 0;
}
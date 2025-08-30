#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
int n, k;
vl nums;

int solve(ll maxi) {
    int tmp = k - 1;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + nums[i] > maxi) {
            tmp--;
            cur = 0;
        }
        cur += nums[i];
    }
    return tmp >= 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    nums.resize(n);
    ll hi = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        hi += nums[i];
    }
    ll lo = *max_element(nums.begin(), nums.end());
    while (lo < hi) {
        ll m = (lo + hi) / 2;
        if (solve(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    } 

    cout << (lo + hi) / 2 << '\n';

    return 0;
}
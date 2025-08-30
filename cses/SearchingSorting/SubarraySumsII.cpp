#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vi nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    map<ll, int> sums;
    sums[0] = 1;
    ll cur = 0;
    ll res = 0;

    for (auto num : nums) {
        cur += num;
        res += sums[cur - x];
        sums[cur]++;
    }
    cout << res << '\n';
    return 0;
}
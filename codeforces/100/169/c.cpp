#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<ll> nums(n), start(n, 0), end(n, 0), sums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end(), greater<ll>());
    
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        start[--a]++;
        end[--b]++;
    }

    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += start[i];
        sums[i] = cur;
        cur -= end[i];
    }
    sort(sums.begin(), sums.end(), greater<ll>());

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += sums[i] * nums[i];
    }

    cout << res << '\n';

    return 0;
}
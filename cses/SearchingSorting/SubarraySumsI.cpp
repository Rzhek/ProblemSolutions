#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int l = 0, r = 0, cur = 0, res = 0;
    while (l < n) {
        // cout << l << "~:" << r << " = " << cur << " " << res << '\n';
        while (r < n) {
            if (cur > x) break;
            cur += nums[r];
            r++;
            // cout << l << ":" << r << " = " << cur << " " << res << '\n';
            if (cur == x) {
                // cout << l << " " << r << '\n';
                res++;
            }
            if (cur >= x) break;
        }
        cur -= nums[l];
        if (cur == x) {
            res++;
            // cout << l << " " << r << '\n';
        }
        l++;
    }

    cout << res << '\n';

    return 0;
}
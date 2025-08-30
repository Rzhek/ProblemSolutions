#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n);
        int res = 0;
        for (int i = 0; i < n; i++) cin >> nums[i];

        for (int x : nums) {
            int r = 0;
            int cur = 0;
            for (int l = 0; l < n; l++) {
                while (r < n && cur < x) {
                    cur += nums[r++];
                }
                if (cur == x && r - l > 1) {
                    res++;
                    break;
                }
                cur -= nums[l];
            }
        }


        cout << res << '\n';
        

    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    vector<int> nums(n);
    for (int k = 0; k < n; k++) cin >> nums[k];    

    int res = 0, cur = 0;
    int i = 0, j = 0;
    while (i < n) {
        while (j < n) {
            if (cur + nums[j] > t) break;
            cur += nums[j];
            j++;
            res = max(res, j - i);
        }
        cur -= nums[i];
        i++;
    }
    

    cout << res << '\n';
    return 0;
}
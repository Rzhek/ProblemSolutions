#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n);
    multiset<int> negative;
    for (int i = 0; i < n; i++) cin >> nums[i];

    ll cur = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (cur + nums[i] < 0) {
            if (!negative.size()) {
                continue;
            }
            auto it = negative.begin();
            if (nums[i] > *it) {
                cur += nums[i];
                cur -= *it;
                negative.erase(it);
                negative.insert(nums[i]);
            }
        } else {
            cur += nums[i];
            res++;
            if (nums[i] < 0) {
                negative.insert(nums[i]);
            }
        }
    }

    cout << res << '\n';



    return 0;
}
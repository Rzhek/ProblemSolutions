#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> good;


pair<int, int> solve(vector<int> &nums, int t, int tar) {
    // {-1,0,1; res}
    int total = 0;
    good.clear();

    for (int i = 0; i < nums.size(); i++) {
        total += t / nums[i];
        if (t % nums[i] == 0) good.push_back(i);
        else total++;
    }

    if (total >= tar) return {-1, 0};
    if (total + good.size() < tar) return {1, 0};
    return {0, good[tar - total - 1]};
    
}

signed main() {
    // cin.tie(0)->sync_with_stdio(0);
    good.reserve(1e5);

    int tt; cin >> tt;
    for (int tc = 1; tc <= tt; tc++) {
        int n, b; cin >> n >> b;
        vector<int> nums(n);
        for (auto &x : nums) cin >> x;

        int lo = 0, hi = 1e13;
        // int x = 5;
        while (true) {
            int m = (lo + hi) / 2;
            // cout << lo << " " << m << " " << hi << "\n";
            auto res = solve(nums, m, b);
            if (res.first == -1) hi = m - 1;
            else if (res.first == 1) lo = m + 1;
            else {
                cout << "Case #" << tc << ": " << (res.second + 1) << "\n";
                break;
            }
        }

        // auto res = solve(nums, 5e6, b);
        // cout << res.first << " " << res.second << "\n";


    }
}
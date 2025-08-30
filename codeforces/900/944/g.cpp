#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, pair<vector<int>, priority_queue<int, vector<int>, greater<int>>>> data;
        vector<int> nums(n);
        forn(i, n) {
            cin >> nums[i];
            data[nums[i] >> 2].first.push_back(i);
            data[nums[i] >> 2].second.push(nums[i]);
        }

        for (auto &[key, val] : data) {
            for (auto ind : val.first) {
                nums[ind] = val.second.top();
                val.second.pop();
            }
        }

        for (auto num : nums) cout << num << ' ';
        cout << '\n';
    }
}
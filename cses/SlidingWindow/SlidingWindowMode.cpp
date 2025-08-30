#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    map<int, int> cnt;
    map<int, set<int>> rev_cnt;
    for (int i = 0; i < n; ++i) {
        auto it = cnt.find(nums[i]);
        if (it != cnt.end()) {
            rev_cnt[it->second].erase(nums[i]);
            it->second++;
            rev_cnt[it->second].insert(nums[i]);
        } else {
            cnt[nums[i]] = 1;
            rev_cnt[1].insert(nums[i]);
        }

        if (i >= k - 1) {
            cout << *rev_cnt.rbegin()->second.begin() << " ";
            
            it = cnt.find(nums[i-k+1]);
            rev_cnt[it->second].erase(nums[i-k+1]);
            if (rev_cnt[it->second].size() == 0) rev_cnt.erase(it->second);
            it->second--;
            if (it->second == 0) {
                cnt.erase(it);
            } else {
                rev_cnt[it->second].insert(nums[i-k+1]);
            }
        }
    }
}
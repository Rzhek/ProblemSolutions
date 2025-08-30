#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n), res(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    stack<pair<int, int>> stk; stk.push({0, 0});
    for (int i = 0; i < n; i++) {
        while (stk.size() && stk.top().first >= nums[i]) stk.pop();
        res[i] = stk.top().second;
        stk.push({nums[i], i + 1});
    }
    for (auto x : res) cout << x << " "; cout << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using vii = vector<pi>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    map<int, vii> memo;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            memo[nums[i] + nums[j]].push_back({i, j});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (memo.find(x - nums[i] - nums[j]) == memo.end()) continue;
            for (auto [a, b] : memo[x - nums[i] - nums[j]]) {
                if (i != a && j != b && i != b && j != a) {
                    cout << i + 1 << " " << j + 1 << " " << a + 1 << " " << b + 1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
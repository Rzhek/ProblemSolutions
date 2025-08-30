#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    map<int, vector<int>> data;
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        data[nums[i]].push_back(i);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (data.find(x - nums[i] - nums[j]) == data.end()) continue;
            for (auto k : data[x - nums[i] - nums[j]]) {
                if (k != i && k != j) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    

    return 0;
}
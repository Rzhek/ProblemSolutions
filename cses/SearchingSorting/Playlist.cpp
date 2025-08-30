#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    rep(i, 0, n) cin >> nums[i];

    set<int> used;
    int i = 0, j = 0, res = 0;
    while (i < n) {
        while (j < n) {
            if (used.count(nums[j])) break;
            used.insert(nums[j]);
            res = max(res, j - i + 1);
            j++;
        }
        used.erase(nums[i]);
        i++;
    }

    cout << res << '\n';
    return 0;
}
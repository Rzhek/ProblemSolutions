#include <bits/stdc++.h>
using namespace std;

bool less(int i, int j) {
    cout << "? " << i << " " << j << endl;
    string ans; cin >> ans;
    return ans == "YES";
}

vector<int> merge(vector<int> &nums, int l, int r) {
    if (l + 1 == r) return {nums[l]};
    int m = (l + r) / 2;
    vector<int> a = merge(nums, l, m);
    vector<int> b = merge(nums, m, r);

    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (::less(a[i] + 1, b[j] + 1)) {
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        res.push_back(a[i]);
        i++;    
    }
    while (j < b.size()) {
        res.push_back(b[j]);
        j++;
    }
    return res;

}

int main() {
    int n; cin >> n;

    vector<int> nums(n), res(n);
    iota(nums.begin(), nums.end(), 0);

    nums = merge(nums, 0, n);

    for (int i = 0; i < n; i++) {
        res[nums[i]] = i + 1;
    }
    cout << "! ";
    for (auto x : res) cout << x << " ";
    cout << endl;
}
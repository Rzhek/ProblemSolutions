#include <bits/stdc++.h>
using namespace std;

int hi = 1000001;

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    vector<int> nums(hi, 0);
    for (int i = 1; i <= hi; ++i) {
        nums[i] = nums[i-1] + !(sqrt(i) == (int)(sqrt(i)));
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cout << nums[b] - nums[a-1] << '\n';
    }


    return 0;
}
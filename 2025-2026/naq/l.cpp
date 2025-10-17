#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;
    int a = nums[0] / 3;
    int c = nums[n-1] / 3;
    int b = nums[1] - 2 * a;
    cout << a << " " << b << " " << c << "\n";
}
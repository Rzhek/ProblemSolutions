#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> nums(n+1, 0);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (!nums[num-1]) res++;
        nums[num] = 1;
    }
    cout << res << '\n';
    return 0;
}
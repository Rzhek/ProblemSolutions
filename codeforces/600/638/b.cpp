#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        set<int> nums;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            nums.insert(a);
        } 
        if (nums.size() > k) {
            cout << "-1\n";
            continue;
        }
        vector<int> arr;
        for (int x : nums) arr.push_back(x);
        cout << n * k << '\n';
        while (arr.size() < k) arr.push_back(1);
        for (int i = 0; i < n; i++) {
            for (int x : arr) cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}
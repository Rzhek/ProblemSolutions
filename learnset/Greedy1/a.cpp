#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        ll res = 0;
        priority_queue<ll, vector<ll>, greater<ll>> nums;
        while (t--) {
            int num; cin >> num;
            nums.push(num);
        }

        while (nums.size() > 1) {
            ll num1, num2, num3;
            num1 = nums.top();
            nums.pop();
            num2 = nums.top();
            // cout << num1 << " " << num2 << endl;
            nums.pop();
            num3 = num1 + num2;
            res += num3;
            nums.push(num3);
        }
        cout << res << endl;
    }

    return 0;
}
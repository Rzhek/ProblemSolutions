#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    if (n * (n + 1) / 2 % 2) {
        cout << "NO\n";
        return 0;
    }

    vector<int> nums(n+1, 0);
    int numFirst = 0;
    ll cur = n * (n + 1) / 4;
    for (int i = n; i > 0; i--) {
        if (cur >= i) {
            nums[i] = 1;
            cur -= i;
            numFirst++;
        } else {
            nums[cur] = 1;
            numFirst += cur != 0;
            break;
        }
    }

    cout << "YES" << '\n';
    cout << numFirst << '\n';
    for (int i = 1; i <= n; i++) {
        if (nums[i]) cout << i << " ";
    }
    cout << '\n';

    cout << (n - numFirst) << '\n';
    for (int i = 1; i <= n; i++) {
        if (!nums[i]) cout << i << " ";
    }
    cout << '\n';




    return 0;
}
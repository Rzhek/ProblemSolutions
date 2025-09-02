#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll res = -1e9, cur = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        cur += num;
        res = max(res, cur);
        if (cur < 0) {
            cur = 0;
        }
    }
    cout << res << '\n';
    return 0;
}
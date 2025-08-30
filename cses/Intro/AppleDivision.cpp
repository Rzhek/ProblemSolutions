#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (int i = a; i < b; ++i)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vl nums(n);
    rep(i, 0, n) cin >> nums[i];
    ll res = 1e9;
    for (int i = 1; i < (1 << n); ++i) {
        ll cur = 0;
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) != 0) cur += nums[j];
            else cur -= nums[j];
        }
        res = min(res, abs(cur));
    }

    cout << res << '\n';

    return 0;
}
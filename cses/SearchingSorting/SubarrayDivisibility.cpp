#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> sums(n, 0);
    sums[0] = 1;
    ll cur = 0, res = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        cur += num;
        cur = (cur % n + n) % n;
        sums[cur]++;
    }

    for (auto x : sums) {
        res += x * (x - 1) / 2;
    }

    cout << res << '\n';

    return 0;
}
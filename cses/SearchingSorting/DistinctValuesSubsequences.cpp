#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<int, int> cnt;
    while (n--) {
        int x; cin >> x;
        cnt[x]++;
    }

    ll res = 1;
    for (auto [x, y] : cnt) {
        res = (res * (y + 1)) % MOD;
    }

    cout << (res - 1) << "\n";
}
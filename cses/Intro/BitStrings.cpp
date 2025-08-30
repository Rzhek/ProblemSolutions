#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9+7;

int main() {
    ll n; cin >> n;
    ll res = 1;
    for (int i = 0; i < n; i++) {
        res = (res * 2) % mod;
    }

    cout << res << '\n';

    return 0;
}
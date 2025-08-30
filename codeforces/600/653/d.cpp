#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        map<ll, ll> remainders;
        for (ll i = 0; i < n; i++) {
            ll a; cin >> a;
            a = ((-a % k) + k) % k; 
            if (remainders.count(a)) remainders[a]++;
            else remainders[a] = 1;
        }

        ll maxI, maxVal = 0;
        for (auto [x, y] : remainders) {
            if (x == 0) continue;
            if (y >= maxVal) {
                maxI = x;
                maxVal = y;
            }
        }

        if (maxVal == 0) cout << "0\n";
        else cout << k * (remainders[maxI] - 1) + maxI + 1 << '\n';
    }
    return 0;
}
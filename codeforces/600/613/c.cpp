#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll x; cin >> x;
    pair<ll, ll> best = {-1, -1};

    for (ll i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (__gcd(i, x / i) != 1) continue;
            if (best.second == -1 || x / i < best.second) {
                best = {i, x / i};
            }
        }
    }

    cout << best.first << " " << best.second << '\n';
    return 0;
}
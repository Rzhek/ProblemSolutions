#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string str; cin >> str;
        map<ll, ll> counter;
        counter[0] = 1;
        ll sum = 0;
        ll res = 0;
        for (ll i = 0; i < n; i++) {
            sum += str[i] - '0';
            ll extraSum = sum - i - 1;
            res += counter[extraSum]++;
        }
        cout << res << '\n';
    }
    return 0;
}
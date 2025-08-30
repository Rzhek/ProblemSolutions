#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll total = n * (n - 1) / 2;
        string res = "";
        ll a = n - 2;
        ll b = 2;
        while (a > 0 || b > 0) {
            ll startWithA = a * total / (a + b);
            if (k > startWithA) {
                // use b
                res += 'b';
                k -= startWithA;
                total -= startWithA;
                b--;
            } else {
                // use a
                res += 'a';
                total = startWithA;
                a--;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
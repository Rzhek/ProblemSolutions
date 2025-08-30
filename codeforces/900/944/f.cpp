#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vi = vector<int>;
using vvi = vector<vi>;

#define f first
#define s second

ll r1, r2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> r1;
        r2 = r1 + 1;

        int res = 0;
        ll hi = r1;
        for (ll x = 0; x <= r1; x++) {
            while (x * x + hi * hi >= r2 * r2) hi--;
            ll y = hi;
            while (x * x + y * y >= r1 * r1 && y > 0) {
                y--;
                res++;
            }
        }

        cout << res * 4 << '\n';
        

    }

    return 0;
}
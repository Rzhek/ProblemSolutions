#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;

    ll first = x, last = x;
    ll cur = x;
    for (int i = 0; i < k - 1; i++) {
        last = (a * last + b) % c;
        cur += last;
    }

    ll res = cur;
    for (int i = k; i < n; i++) {
        cur -= first;
        first = (a * first + b) % c;
        
        last = (a * last + b) % c;
        cur += last;
        res ^= cur;

    }

    cout << res << "\n";
}
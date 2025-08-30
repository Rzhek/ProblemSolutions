#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, left, a, b, c; cin >> n >> k >> left >> a >> b >> c;
    int right = left, cur = 0, res = 0;

    for (int i = 0; i < n; i++) {
        cur ^= right;

        if (i >= k - 1) {
            res ^= cur;
            cur ^= left;
            left = ((ll)left * a + b) % c;
        }
        right = ((ll)right * a + b) % c;
    }

    cout << res << "\n";

}
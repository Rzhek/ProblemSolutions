#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, k, a, b; cin >> n >> k >> a >> b;
        if (n * b < a * (n + 1)) {
            cout << "-1\n";
            continue;
        }
        int res = 0;
        while (k > 0) {

            int need = (n * b) / a;
            int converted = need - n;
            int next = (converted + 1) * a / (b - a);
            
            int totalConverted = max(next - need, converted);

            if (totalConverted < k) {
                int runs = (totalConverted + converted - 1) / converted;
                k -= runs * converted;
                n += runs * converted;
                res += runs;
            } else {
                res += (k + converted - 1) / converted;
                k = 0;
            }
        }
        cout << res << "\n";
    }
}
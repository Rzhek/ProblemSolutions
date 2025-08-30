#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k, a, b; cin >> n >> k >> a >> b;
        ll res = 0;
        while (k > 0) {
            if (a == 0) {
                res = 1;
                break;
            }
            ll newSerious = (n * b) / a;
            if (newSerious <= n) {
                res = -1;
                break;
            }
            ll converted = newSerious - n;
            ll nextN = (converted + 1) * a / (b - a);

            if (nextN < newSerious) nextN = newSerious;

            ll convertedBeforeNextN = max(nextN - newSerious, converted);

            if (k > convertedBeforeNextN) {
                ll runs = ceil((long double)convertedBeforeNextN / converted);
                k -= runs * converted;
                res += runs;
                n += runs * converted;
            } else {
                n += k;
                res += ceil((long double) k / converted);
                k = 0; 
            }
        }
        cout << res << endl;
    }

    return 0;
}
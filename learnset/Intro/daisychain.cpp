#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long n, p, g; cin >> n >> p >> g;
        long long res = (n / g) * ((g - 1) * (p - 1) + p);
        if (n % g) res += (n % g - 1) * (p - 1) + p;
        cout << res << endl;
    }

    return 0;
}
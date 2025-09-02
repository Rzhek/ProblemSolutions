#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int res = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i) continue;
            res++;
            if (i != n / i) res++;
        }
        cout << res << "\n";
    }


    return 0;
}
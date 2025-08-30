#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
    int res = 1;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i <= k) res = max(res, i);
            if (n / i <= k) res = max(res, n / i);
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        cout << n / solve(n, k) << '\n';
    }

    return 0;
}
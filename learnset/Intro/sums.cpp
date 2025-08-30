#include <bits/stdc++.h>
using namespace std;

int T(int n) {
    return n * (n + 1) / 2;
}

int W(int n) {
    int res = 0;
    for (int k = 1; k <= n; ++k) {
        res += k * T(k + 1);
    }
    return res;
}

int main() {
    int t; cin >> t;
    for (int c = 1; c <= t; c++) {
        int n; cin >> n;
        cout << c << " " << n << " " << W(n) << endl;
    }


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void solve(int n) {
    if (n == 1) {
        cout << "FastestFinger\n";
        return;
    }
    if (n == 2) {
        cout << "Ashishgup\n";
        return;
    }
    if (n & 1) {
        cout << "Ashishgup\n";
        return;
    }
    if (log2(n) == (int)log2(n)) {
        cout << "FastestFinger\n";
        return;
    }
    if (isPrime(n / 2)) {
        cout << "FastestFinger\n";
        return;
    }
    cout << "Ashishgup\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        solve(n);
    }

    return 0;
}
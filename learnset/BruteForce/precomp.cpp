#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(ll num, int ind, int n) {
    if (ind > 0 && num == 0) return;
    if (ind && num % ind != 0) return;
    if (ind == n) {
        cout << num << '\n';
        return;
    } 

    num *= 10;
    for (int i = 0; i < 10; i++) {
        solve(num + i, ind + 1, n);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        solve(0, 0, n);
    }

    return 0;
}
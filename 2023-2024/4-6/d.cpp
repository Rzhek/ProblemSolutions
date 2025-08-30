#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii solve(int n) {
    if (n == 1) return {1, 1};
    pii res = solve(n / 2);
    if (n % 2) return {res.first + res.second, res.second};
    return {res.first, res.first + res.second};
}

int main() {
    int t; cin >> t;
    while (t--) {
        int k, n; cin >> k >> n;
        pii res = solve(n);
        cout << k << " " << res.first << "/" << res.second << '\n';
    }

    return 0;
}
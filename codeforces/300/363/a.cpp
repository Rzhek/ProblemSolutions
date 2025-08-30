#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a = {0, 0, 0}, b(3);
    for (int i = 1; i <= n; i++) {
        int day; cin >> day;
        b[2] = (day & 2) ? min(a[0], a[1]) : 1e9;
        b[1] = (day & 1) ? min(a[0], a[2]) : 1e9;
        b[0] = 1 + min({a[0], a[1], a[2]});
        a = b;
    }
    cout << min({b[0], b[1], b[2]}) << '\n';
    return 0;
}
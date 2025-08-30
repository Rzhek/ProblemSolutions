#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll maxi = -1e10;
        ll diff = 0;
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            if (a < maxi) diff = max(diff, maxi - a);
            maxi = max(maxi, a);
        }
        cout << ceil(log2(diff + 1)) << '\n';
    }
}
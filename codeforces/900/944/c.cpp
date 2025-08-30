#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int a1 = min(a, b), a2 = max(a, b);
        int b1 = min(c, d), b2 = max(c, d);
        if (a1 < b1 && b1 < a2 && a2 < b2 || b1 < a1 && a1 < b2 && b2 < a2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}
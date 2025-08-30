#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define f first
#define s second
using pii = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<pii> hui(n);
    rep(i, 0, n) cin >> hui[i].f >> hui[i].s;

    sort(hui.begin(), hui.end());
    int res = 0;
    for (auto [x, y] : hui) {
        if (res <= y) {
            res = y;
        } else {
            res = x;
        }
    }

    cout << res << '\n';

    return 0;
}
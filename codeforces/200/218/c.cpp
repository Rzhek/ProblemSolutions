#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)

using ll = long long;
vector<ll> counts(3, 0), numbers(3), prices(3);
ll r;

int check(ll val) {
    ll money = 0;
    rep(i, 0, 3) money += max((ll)0, (counts[i] * val - numbers[i]) * prices[i]);
    return money <= r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string str; cin >> str;
    for (auto ch : str) {
        if (ch == 'B') counts[0]++;
        if (ch == 'S') counts[1]++;
        if (ch == 'C') counts[2]++;
    }

    rep(i, 0, 3) cin >> numbers[i];
    rep(i, 0, 3) cin >> prices[i];
    cin >> r;

    ll lo = 0, hi = 1e13;
    while (lo <= hi) {
        ll m = (lo + hi) / 2;
        if (check(m)) {
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }

    cout << (lo + hi) / 2 << '\n';
    return 0;
}
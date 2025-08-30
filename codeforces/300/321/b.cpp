#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vii = vector<pi>;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define f first
#define s second

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    vii friends(n);
    rep(i, 0, n) cin >> friends[i].f >> friends[i].s;
    sort(friends.begin(), friends.end());

    int l = 0, r = 0;
    ll res = 0, cur = 0;
    while (l < n) {
        while (r < n) {
            if (friends[r].f - friends[l].f < d) {
                cur += friends[r].s;
                res = max(res, cur);
                r++;
            } else break;
        }
        cur -= friends[l].s;
        l++;

    }

    cout << res << '\n';

    return 0;
}
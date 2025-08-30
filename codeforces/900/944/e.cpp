#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep (i, a, b) for (int i = a; i < b; ++i)
#define forn(i, n) for (int i = 0; i < n; ++i)

using vi = vector<int>;


int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k, q; cin >> n >> k >> q;
        vi dist(k + 1, 0), times(k + 1, 0);
        forn(i, k) cin >> dist[i + 1];
        forn(i, k) cin >> times[i + 1];

        forn(i, q) {
            int x; cin >> x;
            int ind = upper_bound(dist.begin() + 1, dist.end(), x) - dist.begin();
            int ans = times[ind-1] + (x - dist[ind-1]) * 1.0 * (times[ind] - times[ind-1]) / (dist[ind] - dist[ind-1]);
            cout << ans << ' ';
        }
        cout << "\n";
    }
    return 0;
}

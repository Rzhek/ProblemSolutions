#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)

typedef long long ll;
typedef vector<ll> vl;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    rep(tcase, 1, t + 1) {
        int n; cin >> n;
        vl houses(n), dp(n);
        rep(i, 0, n) cin >> houses[i];
        dp[0] = houses[0];
        dp[1] = max(dp[0], houses[1]);
        rep(i, 2, n) {
            dp[i] = max(dp[i-1], dp[i-2] + houses[i]);
        } 

        ll cur = dp.back();
        vl res;
        // rep(i, 0, n) cout << dp[i] << " "; cout << '\n';
        for (int i = n - 1; i >= 0; --i) {
            if (dp[i] == cur) {
                if (i > 0 && dp[i-1] == cur) continue;
                // cout << cur << " | ";
                cur -= houses[i];
                res.push_back(i);
            }
        }
        // cout << '\n';
        cout << "Case #" << tcase << ": " << dp.back() << " : ";
        reverse(res.begin(), res.end());
        rep(i, 0, res.size()) {
            cout << res[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
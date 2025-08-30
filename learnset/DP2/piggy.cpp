#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int E, F; cin >> E >> F;
        vector<ll> dp(F - E + 1, 1e16);
        dp[0] = 0;
        int n; cin >> n;
        while (n--) {
            int val, weight; cin >> val >> weight;
            for (int i = 0; i + weight < dp.size(); i++) {
                dp[i + weight] = min(dp[i + weight], dp[i] + val);
            }
        }
        if (dp[F-E] == 1e16) cout << "This is impossible.\n";
        else cout << "The minimum amount of money in the piggy-bank is " << dp[F-E] << ".\n";
    }
}
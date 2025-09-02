#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vl dp(m + 1, -1);
        dp[0] = 0;
        while (n--) {
            int d, amt; cin >> d >> amt;
            for (int i = m; i >= d; i--) if (dp[i-d] != -1) {
                dp[i] = max(dp[i], dp[i-d] + amt);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}
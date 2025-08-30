#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vi a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<vi> dp(n + 1, vi(m + 1));

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
            if (a[r-1] == b[c-1]) dp[r][c] = max(dp[r][c], dp[r-1][c-1] + 1);
        }
    }
    cout << dp[n][m] << "\n";
    vi res;
    while (dp[n][m] != 0) {
        if (dp[n-1][m] == dp[n][m]) {
            n--;
        } else if (dp[n][m-1] == dp[n][m]) {
            m--;
        } else {
            assert(a[n-1] == b[m-1]);
            assert(dp[n-1][m-1] + 1 == dp[n][m]);
            res.push_back(a[n-1]);
            n--;
            m--;
        }
    }
    reverse(res.begin(), res.end());
    for (auto x : res) cout << x << " ";
    cout << "\n";
}
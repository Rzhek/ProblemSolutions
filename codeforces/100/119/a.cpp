#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<int> wtf = {a, b, c};
    vector<int> dp(n+1, 0);
    if (a <= n) dp[a] = 1;
    if (b <= n) dp[b] = 1;
    if (c <= n) dp[c] = 1;

    for (int i = 1; i < n + 1; ++i) {
        if (dp[i] == 0) continue;
        for (int j : wtf) {
            if (i + j > n) continue;
            dp[i + j] = max(dp[i+j], dp[i] + 1);
        }
    }
    cout << dp.back() << '\n';
    return 0;
}
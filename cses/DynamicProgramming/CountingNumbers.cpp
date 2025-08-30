#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 19;
ll dp[maxn][10]; // index, last digit;
string num;

ll solve(int i = 0, int prev = -1) {
    if (i == num.size()) return 1;
    if (prev != -1 && dp[i][prev] != -1) return dp[i][prev];
    ll res = 0;
    for (int nxt = 0; nxt <= num[i] - '0'; nxt++) {
        if (nxt == prev) continue;
        res += solve(i + 1, nxt);
    }
    if (prev != -1) dp[i][prev] = res;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    int x; cin >> x;
    ll res = 0;
    if (x) {
        num = to_string(x-1);
        res -= solve();
    }

    memset(dp, -1, sizeof(dp));
    cin >> num;
    res += solve();

    cout << res << "\n";
}
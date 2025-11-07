#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 19;
ll dp[maxn][10][2][2]; // index, last digit, prefix match ?;
string num;

ll solve(int i, int last, string &s, int matchPref = 1, int allZeroBefore = 1) {
    if (i == s.size()) return 1;
    ll res = (i == 0) ? -1ll : dp[i][last][matchPref][allZeroBefore];
    if (res != -1) return res;
    res = 0;

    for (int nxt = 0; nxt < 10; nxt++) {
        if (!(nxt == 0 && allZeroBefore) && nxt == last) continue;
        if (matchPref) {
            if (nxt > s[i] - '0') break;
            res += solve(i+1, nxt, s, nxt == s[i] - '0', nxt == 0 && allZeroBefore);
        } else {
            res += solve(i+1, nxt, s, 0, nxt == 0 && allZeroBefore);
        }
    }
    if (i) dp[i][last][matchPref][allZeroBefore] = res;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll a, b; cin >> a >> b;
    
    string A = to_string(a);
    string B = to_string(b);
    
    memset(dp, -1, sizeof(dp));
    ll res = solve(0, -1, B);
    memset(dp, -1, sizeof(dp));
    res -= solve(0, -1, A);

    int works = 1;
    for (int i = 1; i < A.size(); i++) {
        works &= A[i] != A[i-1];
    }
    res += works;
    cout << res << "\n";
}
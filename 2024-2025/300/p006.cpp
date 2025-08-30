#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353, maxn = 1e5+10;
int dp[maxn][10][2][2]; // idx, prev digit, was any non zero before, can get greater than hi
string s;
int hasRepeats = 0;

int solve(int i, int prev, int nonZero, int atLimit = 1) {
    if (i == maxn) return nonZero;
    int &res = dp[i][prev][nonZero][atLimit];
    if (res != -1) return res;
    res = 0;
    for (int j = 0; j < 10; j++) {
        if (j == prev && nonZero) continue;
        if (atLimit && j > s[i] - '0') break;
        res += solve(i + 1, j, nonZero || j, atLimit && j == s[i] - '0');
        res %= MOD;
    }
    return res;
}

int doStuff() {
    memset(dp, -1, sizeof(dp));
    cin >> s;

    char prev = '-';
    for (auto ch : s) {
        hasRepeats |= ch == prev;
        prev = ch;
    }

    reverse(s.begin(), s.end());
    while (s.size() < maxn) s.push_back('0');
    reverse(s.begin(), s.end());

    return solve(0, 0, 0);
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int res = doStuff() - 1 + hasRepeats;
    res = (doStuff() + MOD - res) % MOD;
    cout << res << "\n";
}
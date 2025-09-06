#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 19;
ll dp[maxn][10][2][2]; // index, last digit, on lower bound, on upper bound;
string num;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    int a, b; cin >> a >> b;

    cout << solve(0,)
}
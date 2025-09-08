#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+3;
int dp[maxn][101][101]; // last shot that was reflected
int n, nums[maxn];
vector<int> cd;

int solve(int i, int rem1, int rem2) {
    if (i == n) return 0;
    int &res = dp[i][rem1][rem2];
    if (res != 1e9) return res;

    int nxt = (i < n - 1) ? nums[i + 1] : 1e9;
    int delta = nxt - nums[i];

    if (rem1 == 0) res = min(res, solve(i + 1, max(0, cd[0] - delta), max(0, rem2 - delta)));
    if (rem2 == 0) res = min(res, solve(i + 1, max(0, rem1 - delta), max(0, cd[1] - delta)));
    res = min(res, 1 + solve(i + 1, max(0, rem1 - delta), max(0, rem2 - delta)));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> nums[i];
        sort(nums, nums + n);

        int j; cin >> j;
        cd = vector<int>(j);
        for (auto &x : cd) cin >> x;

        cout << "Mission #" << t << ": ";
        if (j == 1) {
            int ans = n;
            int last = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] >= last) {
                    ans--;
                    last = nums[i] + cd[0];
                }
            } 
            cout << ans << "\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 101; j++) {
                for (int k = 0; k < 101; k++) {
                    dp[i][j][k] = 1e9;
                }
            }
        }
        cout << solve(0, 0, 0) << "\n";
    }
}
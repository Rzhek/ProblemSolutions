#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

using pii = pair<int, int>;
int n;
vector<pii> trees;

int canDropLeft(int ind) {
    return (ind == 0 || trees[ind].f - trees[ind].s > trees[ind-1].f);
}
int canDropLeftIfDroppedRight(int ind) {
    return (ind == 0 || trees[ind].f - trees[ind].s > trees[ind-1].f + trees[ind-1].s);
}
int canDropRight(int ind) {
    return (ind == n - 1 || trees[ind].f + trees[ind].s < trees[ind+1].f);
}

int main() {
    cin >> n;
    trees.resize(n);
    for (int i = 0; i < n; i++) cin >> trees[i].f >> trees[i].s;
    vector<vector<int>> dp(n, vector<int>(3, -1e9)); // 0 left, 1 right, 2 skip
    dp[0][0] = 1;
    dp[0][1] = canDropRight(0);
    dp[0][2] = 0;
    
    for (int i = 1; i < n; ++i) {
        if (canDropLeftIfDroppedRight(i)) {
            dp[i][0] = 1 + max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        } else if (canDropLeft(i)) {
            dp[i][0] = 1 + max(dp[i-1][0], dp[i-1][2]);
        }
        if (canDropRight(i)) {
            dp[i][1] = 1 + max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        }
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    }
    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
    return 0;
}
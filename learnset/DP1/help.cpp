#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    rep(day, 1, t + 1) {
        int n, m; cin >> n >> m;
        vpii questions(n);
        rep (i, 0, n) cin >> questions[i].first >> questions[i].second;
        vii dp(n + 1, vi(m + 1, 0));
        rep(i, 1, n + 1) {
            rep(j, 1, m + 1) {
                auto [time, worth] = questions[i-1];
                dp[i][j] = dp[i-1][j];
                if (time <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-time] + worth);
            }
        }
        cout << "Day #" << day << ": " << dp[n][m] << '\n';
    }
    return 0;
}
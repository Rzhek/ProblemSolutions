#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> reward(n+1);
    vector<double> prob1(n+1), prob2(n+1);
    for (int i = 1; i <= n; i++) cin >> reward[i];
    for (int i = 1; i <= n; i++) cin >> prob1[i];
    for (int i = 1; i <= n; i++) cin >> prob2[i];


    vector<vector<double>> dp(3, vector<double>(n + 1));

    dp[2][0] = 1;
    double res = 0;
    for (int question = 1; question <= n; question++) {
        for (int hints = 2; hints >= 0; hints--) {
            double p1 = dp[hints][question-1] * prob1[question];
            double p2 = hints < 2 ? (dp[hints+1][question-1] * prob2[question]) : 0;

            dp[hints][question] = max(p1, p2);
            res = max(res, reward[question] * dp[hints][question]);
        }
    }

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j <= n; j++) {

    //     }
    // }

    cout << fixed << setprecision(10) << res << "\n";


}
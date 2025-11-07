#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> s(n), a(n), b(n);
    vector<double> dp(n, 0);
    dp[n-1] = 1;

    for (int i = 0; i < n; i++) cin >> s[i] >> a[i] >> b[i];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            double chanceToMake;
            if (s[j] < s[i] + a[i]) chanceToMake = 0;
            else if (s[j] >= s[i] + b[i]) chanceToMake = 1;
            else chanceToMake = (s[j] - (s[i] + a[i]) + 1) / (double)(b[i] - a[i] + 1);

            cout << i << " " << j << " chance " << chanceToMake << "\n";

            dp[i] += 1 + chanceToMake * dp[j];
        }
        dp[i] /= (n - i - 1);
    }

    for (int i = 0; i < n; i++) cout << dp[i] << " "; cout << "\n";

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}
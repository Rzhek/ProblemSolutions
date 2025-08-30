#include <bits/stdc++.h>
using namespace std;

vector<int> getDigits(int num) {
    vector<int> digits;
    while (num != 0) {
        int digit = num % 10;
        digits.push_back(digit);
        num /= 10;
    }
    return digits;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> digits = getDigits(i);
        for (int digit : digits) {
            dp[i] = min(dp[i], dp[i-digit] + 1);
        }
    }

    cout << dp.back() << '\n';
    return 0;
}

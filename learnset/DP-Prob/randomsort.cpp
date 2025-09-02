#include <bits/stdc++.h>
using namespace std;

int n;
map<string, double> dp;

double solve(string &num) {
    if (dp.count(num)) return dp[num];
    int tot = 0;
    double res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (num[i] > num[j]) {
                swap(num[i], num[j]);
                res += 1 + solve(num);
                swap(num[i], num[j]);
                tot++;
            }
        }
    }
    if (tot) return dp[num] = res / tot;
    return dp[num] = 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n;
        string num = "";
        for (int i = 0; i < n; i++) {
            char ch; cin >> ch;
            num += ch;
        }
        cout << solve(num) << "\n";
    }


    return 0;
}
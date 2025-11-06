#include <bits/stdc++.h>
using namespace std;

map<string, double> dp;
double solve(string &s) {
    if (dp.count(s)) return dp[s];
    double total = 0;
    int options = 0;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] > s[j]) {
                swap(s[i], s[j]);
                total += 1 + solve(s);
                swap(s[i], s[j]);
                options++;
            }
        }
    }
    if (options == 0) return dp[s] = 0;
    return dp[s] = total / options;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s += '0' + x; 
        }
        cout << fixed << setprecision(4) << solve(s) << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s1, s2; cin >> s1 >> s2;
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && s2[j] != s1[i]) j++;
            if (j == m) break;
            if (s2[j] == s1[i]) {
                res++; 
                j++; 
            }
        }
        cout << res << '\n';
    }

    return 0;
}
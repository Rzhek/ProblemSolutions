#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string seq; cin >> seq;
        int n = seq.size();
        int res = 1e9;
        int zeros = 0, ones = 0;
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            zeros += seq[i] == '0';
            ones += seq[i] == '1';
        }
        // 111..000
        right = ones;
        for (int i = 0; i < n; i++) {
            res = min(res, left + right);
            left += seq[i] == '0';
            right -= seq[i] == '1';
        }
        res = min(res, left + right);

        // 000..111
        left = 0;
        right = zeros;
        for (int i = 0; i < n; i++) {
            res = min(res, left + right);
            left += seq[i] == '1';
            right -= seq[i] == '0';
        } 
        

        cout << res << '\n';
    }

    return 0;
}
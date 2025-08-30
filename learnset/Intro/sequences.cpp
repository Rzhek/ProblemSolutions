#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> seq(n), newSeq(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> seq[i];
        }
        for (int i = 0; i < n - k; i++) {
            for (int j = 0; j <= k; j++) {
                newSeq[i] += seq[i + j] * (j + 1);
            }
        }
        for (int num : newSeq) cout << num << " "; cout << endl;
    }


    return 0;
}
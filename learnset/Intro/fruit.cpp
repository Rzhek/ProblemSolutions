#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int d; cin >> d;
        vector<int> seq(d);
        int total = 0;
        for (int i = 0; i < d; i++) {
            cin >> seq[i];
            total += seq[i];
        }
        int res = ceil((double)total / d);
        int extra = 0;
        while (1) {
            int curr = 0;
            int success = 1;
            for (int i = 0; i < d; i++) {
                curr += res;
                if (seq[i] > curr) {
                    success = 0;
                    break;
                }
                curr -= seq[i];
                extra = max(extra, curr);
            }
            if (success) break;
            res++;
        }
        cout << res << " " << extra << endl;
    }

    return 0;
}
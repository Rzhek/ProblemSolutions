#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int res = 0;
        while (n--) {
            int s; double p; cin >> s >> p;
            res += ceil(p / 4) * s;
        }
        cout << res << endl;
    }


    return 0;
}
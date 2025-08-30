#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, s; cin >> m >> s;
    vector<int> minRes(m, 0), maxRes(m);
    if (m == 1 && s == 0) {
        cout << "0 0\n";
        return 0;
    }
    if (s == 0 || 9 * m < s) {
        cout << "-1 -1\n";
        return 0;
    }
    int n = s - 1;
    minRes[0] = 1;
    for (int i = m - 1; i >= 0; --i) {
        minRes[i] += min(9, n);
        n -= min(9, n);
    }

    n = s;
    for (int i = 0; i < m; i++) {
        maxRes[i] = min(9, n);
        n -= min(9, n);
    }



    for (int i = 0; i < m; i++) {
        cout << minRes[i];
    }
    cout << ' ';
    for (int i = 0; i < m; i++) {
        cout << maxRes[i];
    }

    cout << '\n';


    return 0;
}
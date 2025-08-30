#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int d, h, m; cin >> d >> h >> m;
        cout << (d * 24 + h) * 60 + m << endl;
    }
    return 0;
}
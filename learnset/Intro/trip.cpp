#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        double a, b, c, d; cin >> a >> b >> c >> d;
        cout << fixed << setprecision(2) << (a * c + b * d) << endl;
    }


    return 0;
}
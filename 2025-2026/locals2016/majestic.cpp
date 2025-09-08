#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    while (n--) {
        int a, b, c; cin >> a >> b >> c;
        cout << a << " " << b << " " << c << "\n";

        int tot = (a >= 10) + (b >= 10) + (c >= 10);

        if (tot == 0) {
            cout << "zilch\n";
        } else if (tot == 1) {
            cout << "double\n";
        } else if (tot == 2) {
            cout << "double-double\n";
        } else if (tot == 3) {
            cout << "triple-double\n";
        }
        cout << "\n";
    }

}
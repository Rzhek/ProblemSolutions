#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string str; cin >> str;
    int a = 0, b = 0;
    int tie = 0;
    for (int i = 0; i < str.size(); i+=2) {
        if (str[i] == 'A') {
            a += (str[i+1] - '0');
            if ((a >= 11 && !tie) || (tie && a - b >= 2)) {
                cout << "A\n";
                return 0;
            }
        } else {
            b += (str[i+1] - '0');
            if ((b >= 11 && !tie) || (tie && b - a >= 2)) {
                cout << "B\n";
                return 0;
            }
        }
        if (a == 10 && b == 10) tie = 1;
    }

    return 0;
}
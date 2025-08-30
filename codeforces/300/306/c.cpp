#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string num; cin >> num;
    int n = num.size();
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                x = (num[i] - '0') * 100 + (num[j] - '0') * 10 + (num[k] - '0'); 
                if (x % 8 == 0) {
                    cout << "YES\n" << x << '\n';
                    return 0;
                }
            }
            x = (num[i] - '0') * 10 + (num[j] - '0') * 1; 
            if (x % 8 == 0) {
                cout << "YES\n" << x << '\n';
                return 0;
            }
        }
        x = (num[i] - '0'); 
        if (x % 8 == 0) {
            cout << "YES\n" << x << '\n';
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
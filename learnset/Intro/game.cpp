#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string keys; cin >> keys;
        int cur = 0, ma = 0;
        for (int i = 0; i < keys.size(); i++) {
            if (keys[i]== 'v') {
                ma = max(ma, ++cur);
            }
            if (keys[i] == '^') {
                cur--;
            }
        }
        cout << ma << endl;
    }


    return 0;
}
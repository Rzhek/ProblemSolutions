#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string word; cin >> word;
        string res = "YES";
        for (int i = 1; i < word.size(); i++) {
            if (word[i] <= word[i-1]) {
                res = "NO";
                break;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}
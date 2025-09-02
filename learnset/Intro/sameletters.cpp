#include <bits/stdc++.h>
using namespace std;

int main() {
    int c = 1;
    while (1) {
        string w1, w2; cin >> w1 >> w2;
        vector<int> counter(26, 0);
        string res = "same";
        if (w1.compare("END") == 0 && w2.compare("END") == 0) return 0;
        for (int i = 0; i < w1.size(); i++) {
            counter[w1[i] - 'a']++;
        }
        // cout << "hello" << endl;
        for (int i = 0; i < w2.size(); i++) {
            counter[w2[i] - 'a']--;
            if (counter[w2[i] - 'a'] < 0) {
                res = "different";
                break;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (counter[i] > 0) {
                res = "different";
                break;
            }
        }
        cout << "Case " << c++ << ": " << res << endl;
    }
    return 0;
}
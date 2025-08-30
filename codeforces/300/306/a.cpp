#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    string word; cin >> word;
    int ab1 = 1e6, ab2 = -1, ba1 = 1e6, ba2 = -1;
    for (int i = 0; i < word.size() - 1; i++) {
        if (word[i] == 'A' && word[i+1] == 'B') {
            ab1 = min(ab1, i);
            ab2 = max(ab2, i);
        }
        if (word[i] == 'B' && word[i+1] == 'A') {
            ba1 = min(ba1, i);
            ba2 = max(ba2, i);
        }
    }

    cout << ((ab1 + 1 < ba2 || ba1 + 1 < ab2) ? "YES" : "NO") << "\n";
    return 0;
}
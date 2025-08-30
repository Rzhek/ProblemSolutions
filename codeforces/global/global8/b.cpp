#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string word = "codeforces";
    vector<int> count(word.size(), 1);
    ll k; cin >> k;
    int ind = 0;
    ll cur = 1;
    while (cur < k) {
        cur /= count[ind%word.size()];
        count[ind%word.size()]++;
        cur *= count[ind++%word.size()];
    }

    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < count[i]; j++) cout << word[i];
    }
    cout << '\n';

    return 0;
}
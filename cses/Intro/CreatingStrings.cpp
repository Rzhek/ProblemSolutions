#include <bits/stdc++.h>
using namespace std;

string str;
set<string> res;

void permute(int ind, vector<char> &cur, vector<int> &used) {
    if (ind == str.size()) {
        // cout << ind << '\n';
        string word(cur.begin(), cur.end());
        res.insert(word);
        return;
    }
    for (int i = 0; i < str.size(); ++i) {
        if (used[i]) continue;
        // cout << i << '\n';
        cur[ind] = str[i];
        used[i] = 1;
        permute(ind + 1, cur, used);
        used[i] = 0;
    }
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    sort(str.begin(), str.end());
    vector<char> cur(str.size());
    vector<int> used(str.size(), 0);
    permute(0, cur, used);

    cout << res.size() << '\n';
    for (string word : res) cout << word << '\n';

    return 0;
}
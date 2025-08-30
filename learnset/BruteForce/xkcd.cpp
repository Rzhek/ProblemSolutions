#include <bits/stdc++.h>
using namespace std;

vector<string> res;
unordered_set<char> vowels{'e', 'y', 'u', 'i', 'o', 'a'};

int isVowel(char chr) {
    return vowels.find(chr) != vowels.end();
}

void solve(vector<char> &word, int ind, int total, int n, vector<int> &used) {
    // cout << "HEWLPLPLPLP\n";
    // for (char x : word) cout << x;
    // cout << " " << ind << " " << total << " " << n << '\n';
    if (ind == n) {
        string newWord(word.begin(), word.end());
        if (total == 42) res.push_back(newWord);
        return;
    }
    if (total > 42) return;
    
    for (char i = 'b'; i <= 'z'; i++) {
        if (isVowel(i)) continue;
        if (used[i-'a']) continue;
        if (ind > 0 && ind == n - 1 && i <= word[ind-1]) continue;
        if (ind > 0 && ind != n - 1 && i >= word[ind-1]) continue;
        if (ind > 2 && ind == n - 1 && i >= word[ind-2]) continue;
        word.push_back(i);
        used[i-'a'] = 1;
        solve(word, ind + 1, total + i - 'a' + 1, n, used);
        word.pop_back();
        used[i-'a'] = 0;
    }
}

int main() {
    cin.tie(0);
    // ios::sync_with_stdio(0);
    // cout << "HELLO PEOPLE\n";

    while (1) {
        int n; cin >> n;
        if (n == 42) break;
        vector<char> word;
        vector<int> used(26, 0);
        solve(word, 0, 0, n, used);
        cout << "XKCD-like name(s) of length: " << n << '\n';
        if (res.size() > 0) {
            sort(res.begin(), res.end());
            for (string &x : res) cout << x << '\n';
        } else {
            cout << "Mostly Harmless\n";
        }
        res.clear();
    }

    cout << "The answer to life, the universe and everything!\n";
    return 0;
}
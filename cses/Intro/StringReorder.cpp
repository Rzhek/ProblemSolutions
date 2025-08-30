#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    for (auto ch : s) {
        if (++cnt[ch-'A'] * 2 > n + 1) { // ? ? ?
            cout << "-1\n";
            return 0;
        }
    } 
    s = "";
    while (n) {
        // we need to find a character s.t. if skipped would result in impossible case. this would happen iff cnt[char] * 2 > n
        // if there is no such character, pick the smallest one
        int mustPick = -1;
        int prev = s.size() ? s.back() - 'A' : -1;
        for (int i = 0; i < 26; i++) if (cnt[i]) {
            if (cnt[i] * 2 > n) mustPick = i;
        }
        if (mustPick != -1) {
            assert(mustPick != prev);
            s += mustPick + 'A';
            cnt[mustPick]--;
            n--;
            continue;
        }
        for (int i = 0; i < 26; i++) if (cnt[i]) {
            if (i == prev) continue;
            s += i + 'A';
            cnt[i]--;
            n--;
            break;
        }
    }
    cout << s << "\n";
}

// a-2
// b-4
// c-6
// n=12

// ca
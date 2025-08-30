#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    vector<int> cnt(26);
    for (char ch : s) cnt[ch - 'a']++;
    int n = s.size();
    vector<char> res(n);
    int cur = 0;
    int middle = -1;
    for (int i = 0; i < 26; i++) {
        while (cnt[i] != 0 && cnt[i] % 2 == 0) {
            res[cur] = res[n - cur - 1] = 'a' + i;
            cur++;
            cnt[i] -= 2; 
        }
        if (cnt[i] != 0) middle = i;
    }

    if (middle != -1) res[n / 2] = 'a' + middle;

    // cout << ": " << res[n / 2] << "\n";
    for (int i = 0; i < n; i++) cout << res[i];
    cout << '\n';
}

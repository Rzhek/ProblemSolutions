#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    for (int tt = 1; tt <= n; tt++) {
        int p; cin >> p;
        vector<char> a(26);
        iota(a.begin(), a.end(), 'a');

        for (int i = 0; i < p; i++) {
            char x, y; cin >> x >> y;
            if (x > y) swap(x, y);
            a[y-'a'] = x;
        }
        cout << "Test case #" << tt << ":\n";
        // for (int i = 0; i < 26; i++) {
        //     cout << 'a' + i << ": " << a[i] << "\n";
        // }
        int q; cin >> q;
        while (q--) {
            string s; cin >> s;
            cout << s << " ";
            for (char & ch : s) ch = a[ch-'a'];

            string s2 = s;
            reverse(s2.begin(), s2.end());
            if (s == s2) cout << "YES\n";
            else cout << "NO\n";
        }
        cout << "\n";
    }

}
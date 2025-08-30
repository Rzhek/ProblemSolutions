#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        multiset<int> razors;
        forn(i, n) cin >> a[i];
        forn(i, n) cin >> b[i];
        int k; cin >> k;
        forn(i, k) {
            int x; cin >> x;
            razors.insert(x);
        }

        int early = 0;
        for (int i = 0; i < n; i++) {
            early += (a[i] < b[i]);
        }
        if (early) {
            cout << "NO\n";
            continue;
        }

        stack<int> stk;
        stk.push(2e9);
        int fail = 0;
        for (int i = 0; i < n; i++) {
            while (stk.top() < b[i]) stk.pop();
            if (b[i] == a[i] || stk.top() == b[i]) continue;
            auto it = razors.find(b[i]);
            if (it != razors.end()) {
                razors.erase(it);
                stk.push(b[i]);
            } else {
                fail = 1;
                break;
            }
        }

        cout << (fail ? "NO" : "YES") << '\n';
    }
    return 0;
}
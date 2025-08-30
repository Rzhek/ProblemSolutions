#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> res = {10000};
        for (int i = 0; i < n - 1; i++) {
            int a; cin >> a;
            res.push_back(a + res.back());
        }
        for (int a : res) cout << a << " "; cout << '\n';
    }
 
    return 0;
}
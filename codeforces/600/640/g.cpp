#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n <= 3) {cout << "-1\n"; continue;}
        vector<int> res;
        for (int i = 1; i <= n; i += 2) res.push_back(i);
        for (int i = (n % 2 == 0 ? n : n - 1); i >= 2; i -= 2) res.push_back(i);

        int a, b;
        if (n % 2 == 0) {
            a = n / 2 - 1;
            b = a - 1;
        } else {
            a = n / 2 + 1;
            b = a + 1;
        }

        int tmp = res[a];
        res[a] = res[b];
        res[b] = tmp;

        for (int x : res) cout << x << " "; cout << '\n';
    }


    return 0;
}
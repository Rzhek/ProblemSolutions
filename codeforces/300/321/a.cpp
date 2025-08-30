#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int res = 0, cur = 0, prev = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (num >= prev) cur++;
        else cur = 1;
        prev = num;
        res = max(res, cur);
    }

    cout << res << '\n';
    return 0;
}
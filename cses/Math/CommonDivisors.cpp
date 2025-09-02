#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> cnt(1e6+1);
    while (n--) {
        int a; cin >> a;
        for (int i = 1; i * i <= a; i++) {
            if (a % i) continue;
            cnt[i]++;
            if (i != a / i) cnt[a/i]++;
        }
    }

    int res = 0;
    for (int i = 1; i <= 1e6; i++) if (cnt[i] > 1) res = i;
    cout << res << "\n";


    return 0;
}
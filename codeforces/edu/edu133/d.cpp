#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<ll> prev(n + 1), res(n + 1), cur(n + 1);
    prev[0] = 1;
    for (int left = 0; left + k <= n; left += k++) {
        for (int i = left; i <= n; i++) {
            for (int j = i - k; j >= left; j -= k) cur[i] += prev[j], cur[i] %= MOD;
            res[i] += cur[i];
            res[i] %= MOD;
        }
        for (int i = 0; i <= n; i++) {
            cout << cur[i] << " ";
        }
        cout << "\n";
        for (int i = left; i < left + k; i++) {
            cur[i] = 0;
        }
        prev = cur;
        cur = vector<ll>(n + 1);
        k++;
    }
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << "\n";
}


//        0 1 2 3 4 5 6 7 8
// k = 0: 1 0 0 0 0 0 0 0 0
// k = 1: 0 1 1 1 1 1 1 1 1
// k = 2: 0 0 0 2 2 3 3 4 4
// k = 3: 0 0 0 2 2 3 3 4 7
// tot:   - 1 1 0 0 0 0 0 0

// k = 2
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, x, a, b, c; cin >> n >> k >> x >> a >> b >> c;
    
    vector<int> last(31, -1e9);
    int res = 0;

    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < 31; j++) {
            if (x & (1 << j)) last[j] = i;
            mask += ((last[j] > i - k) << j);
        }

        res ^= (i >= k - 1) * mask;

        x = ((ll)x * a + b) % c;
    }
    cout << res << "\n";
}
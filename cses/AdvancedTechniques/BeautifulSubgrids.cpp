#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 3e3;
bitset<maxn> dp[maxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        dp[i] = bitset<maxn>(s);
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int N = (dp[i] & dp[j]).count();
            res += N * (N - 1) / 2;
        }
    }
    cout << res << "\n";
}
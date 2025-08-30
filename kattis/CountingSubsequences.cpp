#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unordered_map<ll, int> cnt;
        ll sum = 0;
        int res = 0;
        cnt[0] = 1;
        while (n--) {
            int x; cin >> x;
            sum += x;
            res += cnt[sum - 47];
            cnt[sum]++;
        }
        cout << res << "\n";
        
    }
}
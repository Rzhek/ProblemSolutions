#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 40;
int nums[maxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> nums[i];

    if (n == 1) {
        cout << (x == nums[0]) << "\n";
        return 0;
    }

    vector<int> cnt;
    int n1 = n / 2, n2 = n - n1;

    for (int mask = 0; mask < (1 << n1); mask++) {
        int cur = 0;
        for (int i = 0; cur <= x && i < n1; i++) {
            if (mask & (1 << i)) cur += nums[i];
        }
        if (cur <= x) cnt.push_back(cur);
    }

    sort(cnt.begin(), cnt.end());

    ll res = 0;
    for (int mask = 0; mask < (1 << n2); mask++) {
        int cur = 0;
        for (int i = 0; cur <= x && i < n2; i++) {
            if (mask & (1 << i)) cur += nums[n1 + i];
        }
        if (cur <= x) {
            auto it1 = lower_bound(cnt.begin(), cnt.end(), x - cur);
            if (it1 == cnt.end() || *it1 != x - cur) continue;
            auto it2 = upper_bound(cnt.begin(), cnt.end(), x - cur);

            res += it2 - it1;


        }
    }

    cout << res << "\n";

}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll mini = 1e9, minCount = 0, maxi = 0, maxCount = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (num < mini) {
            mini = num; 
            minCount = 0;
        }
        if (num == mini)
            minCount++;

        if (num > maxi) {
            maxi = num; 
            maxCount = 0;
        }
        if (num == maxi) maxCount++;
    }
    if (maxi != mini) {
        cout << (maxi - mini) << " " << maxCount *  minCount << '\n';
    } else {
        ll k = maxCount;
        cout << 0 << " " << k * k - k * (k + 1) / 2 << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> freq(50);
    int res = 0;
    while (k && n--) {
        int x; cin >> x;
        if (!freq[x-1]++) res++, k--;
    }
    cout << res << "\n";
}
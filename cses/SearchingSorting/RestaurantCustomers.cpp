#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    // priority_queue<pair<int, int>> q;
    map<int, int> data;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (data.count(a)) {
            data[a]++;
        } else {
            data[a] = 1;
        }
        if (data.count(b)) {
            data[b]--;
        } else {
            data[b]--;
        }
    }
    vector<pair<int, int>> arr;
    for (auto &[t, amt] : data) {
        arr.push_back({t, amt});
    }
    
    sort(arr.begin(), arr.end());
    int cur = 0, res = 0;
    for (auto &[_, x] : arr) {
        cur+=x;
        res = max(res, cur);
    }
    cout << res << '\n';
    return 0;
}
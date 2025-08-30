#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    multiset<int> towers;
    while (n--) {
        int num; cin >> num;
        auto it = towers.upper_bound(num);
        if (it == towers.end()) {
            // cout << "inserted " << num << '\n';
            towers.insert(num);
            // cout << towers.size() << '\n';
        } else {
            // cout << "replaced " << *it << " with " << num << '\n';
            towers.erase(towers.find(*it));
            towers.insert(num);
            // cout << towers.size() << '\n';
        }
    }

    cout << towers.size() << '\n';

    return 0;
}
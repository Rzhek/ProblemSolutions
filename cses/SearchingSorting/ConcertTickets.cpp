#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        tickets.insert(num);
    }
    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        auto it = tickets.upper_bound(num);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            cout << *(--it) << '\n';
            tickets.erase(it);
        }
    }

    return 0;
}
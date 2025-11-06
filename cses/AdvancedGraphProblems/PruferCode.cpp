#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> order(n-2);
    vector<vector<int>> adj(n+1);

    for (auto &x : order) cin >> x;

    int last = n;
    set<int> guys;
    for (int i = 1; i <= n; i++) if (i != n) guys.insert(i);

    while (order.size()) {
        int x = order.back(); order.pop_back();
        if (guys.count(x)) {
            // can take the guy
            adj[last].push_back(x);
            last = x;
            guys.erase(last);
        } else {
            // take the biggest guy
            auto y = *guys.rbegin();
            adj[last].push_back(y);
            guys.erase(y);
            last = x;
        }
    }
    adj[last].push_back(*guys.begin());

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) cout << u << " " << v << "\n";
    }
}
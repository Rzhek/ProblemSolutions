#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int solve(vector<vi> &adj, int u) {
    if (adj.size() == 0) return 0;
    vi data;
    for (auto v : adj[u]) {
        data.push_back(solve(adj, v));
    }
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
    int res = 0;

    for (int i = 0; i < data.size(); i++) {
        res = max(res, data[i] + i + 1);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tests; cin >> tests;
    while (tests--) {
        int n; cin >> n;
        vector<vi> adj(n);
        for (int i = 1; i < n; i++) {
            int u; cin >> u;
            adj[u].push_back(i);
        }
        cout << solve(adj, 0) << "\n";
    }
}
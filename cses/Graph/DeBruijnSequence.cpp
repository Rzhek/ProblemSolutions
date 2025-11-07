#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n == 1) return cout << "10\n", 0;

    vector<vector<int>> adj(1 << (n-1));
    for (int u = 0; u < (1 << (n-1)); u++) {
        int v = (u << 1) & ((1 << (n-1)) - 1); 
        adj[u].push_back(v);
        adj[u].push_back(v + 1);
    }

    vector<int> stk{0};
    while (stk.size()) {
        int u = stk.back();
        if (adj[u].size()) {
            stk.push_back(adj[u].back());
            adj[u].pop_back();
        } else {
            cout << u % 2;
            stk.pop_back();
        }
    }

    for (int i = 0; i < n - 2; i++) cout << 0;
    cout << "\n";
}
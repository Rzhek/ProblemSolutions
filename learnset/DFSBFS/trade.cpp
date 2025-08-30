#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;

int main() {
    int c; cin >> c;
    while (c--) {
        int n, s; cin >> n >> s;
        vl values(s);
        for (int i = 0; i < s; i++) cin >> values[i];
        ll res = values[0]; 
        // unordered_map<int, int> edges;
        vll edges(s);
        for (int i = 0; i < n; i++) {
            int d, t; cin >> d >> t;
            for (int j = 0; j < t; j++) {
                int val; cin >> val;
                edges[val-1].push_back(d-1);
            }
        }

        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                if (visited.count(v) == 0) {
                    res = max(res, values[v]);
                    q.push(v);
                    visited.insert(v);
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
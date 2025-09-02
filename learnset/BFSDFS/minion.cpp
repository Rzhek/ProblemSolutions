#include <bits/stdc++.h>
using namespace std;

int main() {
    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        unordered_set<string> trials;
        for (int i = 0; i < t; i++) {
            string temp; cin >> temp;
            trials.emplace(temp);
        }

        int n, e; cin >> n >> e;
        vector<vector<pair<int, string>>> edges(n);
        for (int i = 0; i < e; i++) {
            int u, v; cin >> u >> v;
            string trial; cin >> trial;
            edges[u].push_back({v, trial});
            edges[v].push_back({u, trial});
        }

        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.emplace(0);
        int res = 0;

        while (!q.empty() && !res) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < edges[u].size(); i++) {
                int v = edges[u][i].first;
                string trial = edges[u][i].second;
                if (visited.find(v) == visited.end() && trials.find(trial) == trials.end()) {
                    if (v == n - 1) {
                        res = 1;
                        break;
                    }
                    q.push(v);
                    visited.emplace(v);
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, string, string> val;

int main() {

    int t; cin >> t;
    while (t--) {
        map<string, map<string, vector<int>>> edges;
        map<string, int> indegree;
        int f; cin >> f;
        for (int i = 0; i < f; i++) {
            string u, v;
            int w;
            cin >> u >> v >> w;
            edges[u][v].push_back(w);
            if (indegree.count(v) == 0) {
                indegree[v] = 1;
            } else {
                indegree[v] += 1;
            }
        }

        priority_queue<val, vector<val>, greater<val>> pq;
        for (const auto & [u, a] : edges) {
            if (indegree.count(u) == 0) {
                for (const auto & [v, b] : a) {
                    // tuple<int, string, string> res = {w, u, v};
                    // cout << 1 << " | " << u << " | " << v << endl;
                    for (int w : b) {
                        // cout << w << " | " << u << " | " << v << endl;
                        pq.push({w, u, v});
                    } 
                }
            }

        // cout << pt.size() << '\n';
        // while (!pt.empty()) {
        //     pt.pop();
        //     auto [w, u, v] = pt.top();
        //     cout << w << " | " << u << " | " << v << endl;
        // }

        }
        while (!pq.empty()) {
            auto [w, u, v] = pq.top();
            pq.pop();
            cout << w << ' ';
            indegree[v]--;
            if (indegree[v] == 0) {
                for (const auto & [newV, flights] : edges[v]) {
                    for (int flight : flights) {
                        pq.push({flight, v, newV});
                    }
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int main() {
    int n; cin >> n;
    for (int city = 1; city <= n; city++) {
        cout << "City #" << city << '\n';
        int k; cin >> k;
        vii edges(k);
        for (int i = 0; i < k; i++) {
            int l; cin >> l;
            for (int j = 0; j < l; j++) {
                int u; cin >> u;
                edges[i].push_back(u - 1);
                edges[u - 1].push_back(i);
            }
        }
        int c; cin >> c;
        while (c--) {
            int acc; cin >> acc;
            acc--;
            int start = acc == 0;
            queue<int> q;
            q.push(start);
            unordered_set<int> visited;
            visited.insert(start);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : edges[u]) {
                    if (v != acc && visited.find(v) == visited.end()) {
                        q.push(v);
                        visited.insert(v);
                    }
                }
            }
            cout << ((visited.size() == k - 1) ? "no" : "yes") << '\n';
        }
        cout << '\n';
    }


    return 0;
}
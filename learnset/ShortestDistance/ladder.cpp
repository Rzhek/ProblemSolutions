#include <bits/stdc++.h>
using namespace std;

vector<int> dontMatch(string &s1, string &s2) {
    vector<int> res;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) res.push_back(i);
    }
    return res;
}

using bruh = tuple<int, string, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];


    vector<vector<int>> basic(n);
    vector<vector<pair<int, string>>> idk(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> diff = dontMatch(dict[i], dict[j]);
            if (diff.size() == 1) {
                basic[i].push_back(j);
                basic[j].push_back(i);
            }
            if (diff.size() == 2) {
                int i1 = diff[0], i2 = diff[1];
                // string type1 = dict[i].substr(0, i1);
                // type1 += dict[j][i1];
                // type1 += dict[i].substr(i1 + 1);
                string type1 = dict[i];
                type1[i1] = dict[j][i1];
                idk[i].emplace_back(j, type1);
                idk[j].emplace_back(i, type1);

                // type1 = dict[i].substr(0, i2);
                // type1 += dict[j][i2];
                type1[i1] = dict[i][i1];
                type1[i2] = dict[j][i2];
                // cout << dict[i] << " - > " << type1 << " -> " << dict[j] << "\n";
                idk[i].emplace_back(j, type1);
                idk[j].emplace_back(i, type1);
            }
        }
    }

    priority_queue<bruh, vector<bruh>, greater<bruh>> pq;
    pq.emplace(0, "0", 0);
    vector<vector<int>> dist(n, vector<int>(2, 1e9));
    // set<string> seen;
    while (pq.size()) {
        auto [w, str, u] = pq.top();
        pq.pop();
        if (u == 1) {
            cout << str << "\n" << w << "\n";
            return 0;
        }
        if (dist[u][str != "0"] < w) continue;
        dist[u][str != "0"] = w;

        for (int v : basic[u]) {
            if (dist[v][str != "0"] < w + 1) continue;
            dist[v][str != "0"] = w + 1;
            pq.emplace(w + 1, str, v);
        }

        if (str != "0") continue;
        for (auto [v, s] : idk[u]) {
            if (dist[v][1] < w +     2) continue;
            dist[v][1] = w + 2;
            pq.emplace(w + 2, s, v);
        }
    }

    cout << "0\n-1\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> candidates;
    map<string, vector<string>> supporters;
    set<string> seen;
    for (int i = 0; i < n; i++) {
        string cand; cin >> cand;
        candidates.push_back(cand);
        seen.insert(cand);
    }
    for (int i = 0; i < m; i++) {
        string sup, cand; cin >> sup >> cand;
        if (seen.count(cand) == 0) {
            candidates.push_back(cand);
            seen.insert(cand);
        }
        supporters[cand].push_back(sup);
    }

    for (string cand : candidates) {
        for (string sup : supporters[cand]) {
            cout << sup << '\n';
        }
    }


    return 0;
}
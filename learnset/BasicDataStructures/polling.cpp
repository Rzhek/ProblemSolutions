#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> votes;
    int ma = 0;
    vector<string> res;
    while (n--) {
        string name; cin >> name;
        if (votes.count(name) == 0) {
            votes[name] = 1;
        } else {
            votes[name]++;
        }
        if (votes[name] > ma) {
            ma = votes[name];
            res.clear();
            res.push_back(name);
        } else if (votes[name] == ma) {
            res.push_back(name);
        }
    }
    sort(res.begin(), res.end());
    for (string name : res) {
        cout << name << '\n';
    }


    return 0;
}
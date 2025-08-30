#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
using ll = long long;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<string, ll> counts;
    vector<pair<string, ll>> data(n);
    for (int i = 0; i < n; i++) cin >> data[i].f >> data[i].s;
    for (auto &[name, score] : data) {
        counts[name] += score;
    }

    ll best = -1e18;
    set<string> winners;
    for (auto &[name, score] : counts) {
        if (score > best) {
            winners.clear();
            winners.insert(name);
            best = score;
        } else if (score == best) {
            winners.insert(name);
        }
    }


    counts.clear();
    for (auto &[name, score] : data) {
        counts[name] += score;
        if (counts[name] >= best && winners.count(name)) {
            cout << name << '\n';
            return 0;
        }
    }

    return 0;
}
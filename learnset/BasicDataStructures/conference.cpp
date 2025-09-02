#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> psi; // name, duration
typedef tuple<string, int, int> sii; // name, room, start time
typedef tuple<int, int, int> iii; // end time, room, ind

bool sim(vector<psi> &names, int n, int t, vector<sii> &res) {
    res.clear();
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    int lastRoom = 0;
    for (int i = 0; i < names.size(); i++) {
        if (pq.size() < n) {
            pq.push({names[i].second, lastRoom, i});
            res.push_back({names[i].first, lastRoom, 0});
            lastRoom++;
        }  else {
            auto [endTime, room, ind] = pq.top();
            auto [name, dur] = names[i];
            int newTime = endTime + dur;
            if (newTime > t) return false;

            pq.push({endTime + dur, room, i});
            res.push_back({name, room, endTime});
            pq.pop();
        }
    }
    return true;
}

int main() {
    int n, t; cin >> n >> t;
    vector<psi> classes(n);
    for (int i = 0; i < n; i++) {
        string name; int time;
        cin >> name >> time;
        classes[i] = {name, time};
    }

    int lo = 1, hi = n;
    vector<sii> res;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (sim(classes, m, t, res)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    sim(classes, (lo + hi) / 2, t, res);
    sort(res.begin(), res.end());
    cout << (lo + hi) / 2 << '\n';
    for (auto [name, room, startTime] : res) {
        cout << name << " " << room << " " << startTime << '\n';
    }


    return 0;
}
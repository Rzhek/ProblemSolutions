#include <bits/stdc++.h>
using namespace std;

vector<int> cows;

int sim(int k, int t) {
    priority_queue<int, vector<int>, greater<int>> scene;

    for (int cow : cows) {
        if (scene.size() < k) {
            scene.push(cow);
        } else {
            int newTime = scene.top() + cow;
            if (newTime > t) return 0;
            scene.push(newTime);
            scene.pop();
        }
    }
    return 1;
}

int main() {
    int n, t; cin >> n >> t;
    cows = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> cows[i];

    int lo = 1, hi = n;
    while (lo < hi) {
        int m = (hi + lo) / 2;
        if (sim(m, t)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << (lo + hi) / 2 << '\n';
    return 0;
}
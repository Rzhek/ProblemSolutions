#include <bits/stdc++.h>

using namespace std;

void printq(priority_queue<pair<int, int>> q) {
    while (!q.empty()) {
        cout << "(" << -q.top().first << ", " << -q.top().second << ") ";
        q.pop();
    }
    cout << endl;
}

int main() {

    priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({-1, 10});
    q.push({-3, 10});
    q.push({-5, 10});
    q.push({-4, 10});

    // printq(q);


    return 0;
}
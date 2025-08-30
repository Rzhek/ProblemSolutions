#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    int removed = 0;
    while (!q.empty()) {
        int el = q.front();
        q.pop();
        if (removed) {
            cout << el << " ";
        } else {
            q.push(el);
        }
        removed ^= 1;
    }
    
    cout << '\n';

    return 0;
}
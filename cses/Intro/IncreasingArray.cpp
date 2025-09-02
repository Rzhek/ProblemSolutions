#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    int prev = 0, cur;
    ll moves = 0;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        moves += max(0, prev - cur);
        prev = cur + max(0, prev - cur);
    }

    cout << moves << '\n';

    return 0;
}
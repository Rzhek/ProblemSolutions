#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int cur = n - k + 1;
    for (int i = 0; i < k; i++) {
        cout << cur++ << " ";
    }
    cur = n - k;
    for (int i = k; i < n; i++) {
        cout << cur-- << " ";
    }
    cout << "\n";

    return 0;
}
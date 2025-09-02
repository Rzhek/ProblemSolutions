#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &items, vector<string> &comb, int ind, int k) {
    if (k == 0) {
        for (string item : comb) {
            cout << item << ' ';
        } 
        cout << '\n';
        return;
    }
    if (ind >= items.size()) return;
    for (int i = ind; i < items.size(); i++) {
        comb.push_back(items[i]);
        solve(items, comb, i + 1, k - 1);
        comb.pop_back();
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<string> items(n);
        for (int i = 0; i < n; i++) cin >> items[i];
        sort(items.begin(), items.end());
        vector<string> comb;
        solve(items, comb, 0, k);
        cout << '\n';
    }

    return 0;
}
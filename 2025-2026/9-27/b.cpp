#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int nxt[maxn];

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    string ln;
    getline(cin, ln, '\n');
    int a, b; cin >> a >> b;

    vector<int> sums = {-1};
    stringstream stream(ln);
    string s;
    while (getline(stream, s, ' ')) {
        sums.push_back(s.size());
    }

    int n = sums.size();
    for (int i = 1; i < n; i++) {
        sums[i] += sums[i-1] + 1;
        nxt[sums[i]] = i;
    }

    int cur = 0;
    for (int i = 0; i < maxn; i++) {
        nxt[i] = cur = max(cur, nxt[i]);
    }
    // cout << sums[172] << "\n";

    for (int i = a; i <= b; i++) {
        int res = 0;
        int idx = 0;
        // cout << i << ":\n";
        while (idx + 1 < n) {
            // cout << i << " " << idx << " " << res << "\n";
            res += sums[idx+1]-sums[idx];
            idx = nxt[sums[idx]+i+1];
        }
        // cout << idx << " " << res << "!!!\n";
        cout << res - 1 << "\n";
    }





}
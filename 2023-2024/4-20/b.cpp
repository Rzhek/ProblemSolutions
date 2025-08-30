#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> seq;
    vector<int> used(200'000'001, 0);
    int a1, m; cin >> a1 >> m;
    seq.push_back(a1);
    used[a1] = 1;

    for (int i = 1; i <= m; i++) {
        if (used[m]) break;
        if (used[i]) continue;
        int num = seq.back() + i;
        seq.push_back(num);
        used[num] = 1;
        used[i] = 1;
        for (int j = seq.size() - 3; j >= 0; j--) {
            used[num - seq[j]] = 1;
        }
    }
    cout << seq.size() << '\n';
    return 0;
}
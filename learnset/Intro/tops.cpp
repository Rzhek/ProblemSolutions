#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    for (int c = 1; c <= n; c++) {
        int k; cin >> k;
        int mi = 1e8, ma = -1e8;
        vector<int> scores(k);
        for (int i = 0; i < k; i++) {
            string name; cin >> name;
            int score; cin >> score;
            mi = min(mi, score);
            ma = max(ma, score);
            scores[i] = score;
        }
        sort(scores.begin(), scores.end());
        double med;
        if (k % 2) {
            med = scores[k / 2 ];
        } else {
            med = (scores[k / 2 - 1] + scores[k / 2]) / 2.0;
        }
        cout << "Case #" << c << ": " << ma << " " << mi << " " << med << endl;
    }

    return 0;
}
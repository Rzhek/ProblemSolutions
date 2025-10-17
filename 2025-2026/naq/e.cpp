#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int res1 = 0, res2 = 0;
    for (int round = 0; round < 10; round++) {
        vector<int> a, b;
        int n; cin >> n;
        while (n--) {
            int x, y; cin >> x >> y;
            int dx = 144 - x;
            int dy = 84 - y;
            a.push_back(dx * dx + dy * dy);
        }
        n; cin >> n;
        while (n--) {
            int x, y; cin >> x >> y;
            int dx = 144 - x;
            int dy = 84 - y;
            b.push_back(dx * dx + dy * dy);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a.size() == 0) res2 += b.size();
        else if (b.size() == 0) res1 += a.size();
        else {
            if (a[0] < b[0]) for (int i = 0; i < a.size(); i++) {
                if (a[i] > b[0]) break;
                else res1++;
            } else for (int i = 0; i < b.size(); i++) {
                if (b[i] > a[0]) break;
                else res2++;
            }
        }
    }
    cout << res1 << " " << res2 << "\n";
}
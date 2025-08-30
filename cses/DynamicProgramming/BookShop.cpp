#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<int> res(x+1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if ((j == 0 || res[j]) && (j + prices[i] <= x)) {
                res[j + prices[i]] = max(res[j + prices[i]], res[j] + pages[i]);
            }
        }
    }

    cout << *max_element(res.begin(), res.end()) << '\n';
    return 0;
}
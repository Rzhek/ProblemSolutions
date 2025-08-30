// p003 problem was hard
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s, p, q; cin >> n >> m >> s >> p >> q;
    s--;
    int pageNum = n / m + (n % m != 0);
    vi isSelected(n), needToSelect(n), bestAction(pageNum);

    for (int i = 0; i < p; i++) {
        int a; cin >> a;
        isSelected[a-1] = 1;
    }

    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        needToSelect[a-1] = 1;
    }

    int lo = 1e9, hi = -1;
    for (int page = 0; page < pageNum; page++) {
        int selectAll = 1, deselectAll = 1, indiv = 0;
        for (int item = page * m; item < min(page * m + m, n); item++) {
            if (needToSelect[item]) {
                deselectAll++;
            } else {
                selectAll++;
            }
            indiv += needToSelect[item] != isSelected[item];
        }
        bestAction[page] = min({selectAll, deselectAll, indiv});
        if (bestAction[page]) {
            lo = min(lo, page);
            hi = page;
        }
    }

    int total = accumulate(bestAction.begin(), bestAction.end(), 0);
    if (total) {
        total += hi - lo;
        total += min(abs(s - lo), abs(s - hi));
    }

    cout << total << "\n";
}
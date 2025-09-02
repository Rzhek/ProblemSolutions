#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vi people(n);
    vi apps(m);
    for (int i = 0; i < n; i++) cin >> people[i];
    for (int i = 0; i < m; i++) cin >> apps[i];
    sort(all(people));
    sort(all(apps));

    int curA = 0;
    int res = 0;
    for (int p = 0; p < n; p++) {
        for (int a = curA; a < m; a++) {
            if (abs(people[p] - apps[a]) <= k) {
                res++;
                curA = a + 1;
                break;
            } else if (apps[a] > people[p]) break;
        }
    }
    cout << res << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

using pi = pair<int, int>;
using vii = vector<pi>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vii movies(n);
    for (int i = 0; i < n; i++) cin >> movies[i].f >> movies[i].s;
    sort(movies.begin(), movies.end(), [](auto x, auto y) {
        return x.s != y.s ? x.s < y.s : x.f < y.f;
    });
    int res = 0;
    int cur = 0;
    for (auto [a, b] : movies) {
        if (cur <= a) {
            cur = b;
            res++;
        }
    }
    cout << res << '\n';

    return 0;
}
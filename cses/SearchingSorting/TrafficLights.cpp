#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, n; cin >> x >> n;

    set<int> lights{0, x};
    multiset<int> dist{x};
    for (int i = 0; i < n; i++) {
        int pos; cin >> pos;
        auto next = lights.upper_bound(pos);
        auto prev = next;
        --prev;

        dist.erase(dist.find(*next - *prev));
        dist.insert(pos - *prev);
        dist.insert(*next - pos);
        lights.insert(pos);

        auto ma = dist.end();
        cout << *--ma << ' ';
    }
    cout << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vvi times(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        times[i] = {a, b, i};
    }

    sort(times.begin(), times.end());

    priority_queue<pi, vector<pi>, greater<pi>> q;
    vi data(n, 0);

    for (int i = 0; i < n; i++) {
        int t1 = times[i][0], t2 = times[i][1], ind = times[i][2];
        if (q.size() && q.top().f < t1) {
            int room = q.top().s;
            q.pop();
            q.push({t2, room});
            data[ind] = room;
        } else {
            q.push({t2, (int)q.size() + 1});
            data[ind] = q.size();
        }
    }

    cout << q.size() << '\n';
    for (int x : data) cout << x << " "; cout << '\n';

    return 0;
}
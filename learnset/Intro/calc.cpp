#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    while (n--) {
        ll a, b, c, t;
        cin >> a >> b >> c >> t;
        vector<int> dist(1e6, -1);
        dist[0] = 0;
        queue<ll> q;
        q.push(0);
        int steps = 0;
        int res = -1;

        while (!q.empty() && res == -1) {
            ll cur = q.front();
            q.pop();
            vector<ll> nums;
            nums.push_back((cur + a) % 1000000);
            nums.push_back((cur * b) % 1000000);
            nums.push_back((cur / c) % 1000000);
            for (ll num : nums) {
                if (t == num) {
                    res = dist[cur] + 1;
                    break;
                }
                if (dist[num] == -1) {
                    dist[num] = dist[cur] + 1;
                    q.push(num);
                }
            }
        }
        // cout << steps << endl;
        cout << res << endl;
    }


    return 0;
}
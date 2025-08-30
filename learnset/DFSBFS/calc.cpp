#include <bits/stdc++.h>
using namespace std;

typedef long int ll;

int main() {
    int n; cin >> n;
    while (n--) {
        ll a, b, c, t;
        cin >> a >> b >> c >> t;
        if (t == 1) {
            cout << 0 << endl;
            continue;
        }
        set<ll> seen;
        queue<ll> q;
        q.push(1);
        int steps = 0;
        bool found = false;

        while (!q.empty()) {
            ll len = q.size();
            for (int i = 0; i < len; i++) {
                ll cur = q.front();
                q.pop();
                vector<ll> nums;
                nums.push_back((cur + a) % 1000000);
                nums.push_back((cur * b) % 1000000);
                nums.push_back((cur / c) % 1000000);
                for (ll num : nums) {
                    if (t == num) {
                        found = true;
                        break;
                    }
                    if (seen.find(num) == seen.end()) {
                        seen.insert(num);
                        q.push(num);
                    }
                }
            }
            steps++;
            if (found) break;
        }
        // cout << steps << endl;
        cout << (found ? steps + 1 : -1 ) << endl;
    }


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<tuple<ll, ll, ll>> projects(n);
    for (int i = 0; i < n; i++) {
        int start, end, reward;
        cin >> start >> end >> reward;
        projects[i] = {end, start, reward};
    }
    sort(projects.begin(), projects.end());
    map<ll, ll> dp;
    dp[0] = 0;

    ll res = 0;
    for (auto &[end, start, reward] : projects) {
        auto it = dp.lower_bound(start);
        it--;
        res = max(res, it->second + reward);
        dp[end] = res;
    }

    cout << res << '\n';
    return 0;
}
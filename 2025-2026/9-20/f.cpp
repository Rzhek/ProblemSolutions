#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, l, k; cin >> n >> l >> k;
    vector<string> names(n);
    vector<vi> coords(n, vi(l));
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        for (int j = 0; j < l; j++) cin >> coords[i][j];
    }

    vi res, taken(n), dp(n, 1e9);
    res.reserve(k);

    int bestIdx = 0, bestDist = 0;
    for (int i = 1; i < n; i++) {
        int dist = 0;
        for (int j = 0; j < l; j++) dist += abs(coords[0][j] - coords[i][j]);
        if (dist > bestDist) bestIdx = i, bestDist = dist; 
    }
    res.push_back(bestIdx);
    taken[bestIdx] = 1;

    for (int kk = 1; kk < k; kk++) {

        for (int i = 0; i < n; i++) if (!taken[i]) {
            int dist = 0;
            for (int j = 0; j < l; j++) dist += abs(coords[bestIdx][j] - coords[i][j]);
            dp[i] = min(dp[i], dist);
        } 

        bestIdx = 0;
        for (int i = 1; i < n; i++) if (!taken[i]) {
            if (taken[bestIdx] || dp[bestIdx] < dp[i]) bestIdx = i;
        }

        res.push_back(bestIdx);
        taken[bestIdx] = 1;

    }

    for (int i : res) cout << names[i] << "\n";

}
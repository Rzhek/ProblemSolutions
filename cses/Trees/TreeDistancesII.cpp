#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
const int maxn = 2e5+5;
int n, cnt[maxn];
ll dp[maxn];
vi adj[maxn];

void dfs1(int u, int p = -1) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u] += cnt[v] + dp[v];
        cnt[u] += cnt[v];
    }
}

void dfs2(int u, int p = -1, ll take_val = 0, ll take_cnt = 0) {
    ll new_val = 0;
    ll new_cnt = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        new_val += dp[v];
        new_cnt += cnt[v];
    }
    // cout << u + 1 << ": " << take_val << " " << take_cnt << " & " << new_val << " " << new_cnt << "\n";

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u, take_val + take_cnt + (new_val - dp[v]) + 2 * (new_cnt - cnt[v]) + 1, take_cnt + new_cnt - cnt[v] + 1);
    }
    dp[u] += take_val;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) cnt[i] = 1;

    dfs1(0);
    dfs2(0);

    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    // cout << "\n";
    // for (int i = 0; i < n; ++i) {
    //     cout << cnt[i] << " ";
    // }
    cout << "\n";
}
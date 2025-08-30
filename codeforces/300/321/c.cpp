#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

#define rep(i, a, b) for (int i = a; i < b; ++i)

int m;
vi cats;
vii edges;

int solve(int u, int prev, int streak) {
    if (cats[u]) streak++;
    else streak = 0;

    if (streak > m) return 0;
    int num = 0;
    int res = 0;
    for (int v : edges[u]) {
        if (v == prev) continue;
        res += solve(v, u, streak);
        num++;
    }
    if (num == 0) return 1;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n >> m;
    cats.resize(n);
    edges.resize(n);
    rep(i, 0, n) cin >> cats[i];
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    cout << solve(0, -1, 0) << '\n';

    return 0;
}
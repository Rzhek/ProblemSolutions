#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;

int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
	cin.tie(0)->sync_with_stdio(0);
    // ifstream fin("speed.in");
	// ofstream fout("speed.out");
    int n, m; cin >> n >> m;
    vvpll edges(n);
    vl dist(n, 1e18);
    for (int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u].push_back({v, w});
    }

    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
		const auto [w, u] = pq.top();
		pq.pop();
        if (dist[u] <= w) continue;
        dist[u] = w;
		for (const auto &[v, dw] : edges[u]) {
			if (w + dw >= dist[v]) continue;
            pq.push({w + dw, v});
			
		}
	}

    for (auto &x : dist) cout << x << " ";
    cout << '\n';
    return 0;
}
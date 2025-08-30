#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)

using ll = long long;
using vi = vector<int>;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    Dinic d(2 + 2 * n + n * n);
    int s = 2 * n + n * n, t = s + 1;
    int totR = 0, totC = 0;

    // for rows
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) d.addEdge(s, i, x);
        totR += x;
    }
    // for cols
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) d.addEdge(n + i, t, x);
        totC += x;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            d.addEdge(r, n + c, 1);
        }
    }

    if (totR != totC || totC != d.calc(s, t)) {
        cout << "-1\n";
        return 0;
    }

    vector<string> res(n, string(n, '.'));

    for (int r = 0; r < n; r++) {
        for (auto &edge : d.adj[r]) {
            int c = edge.to - n;
            if (c < 0 || c >= n || edge.flow() == 0) continue;
            res[r][c] = 'X';
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << res[r][c];
        }
        cout << "\n";
    }

}
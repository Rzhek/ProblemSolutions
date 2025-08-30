#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int n, m, s, t;

int dfs(vii &graph, vi &visited, int u, int flow) {
    if (u == t) return flow;
    if (visited[u]) return 0;
    visited[u] = 1;
    for (int v = 0; v < n + m + 2; v++) {
        if (graph[u][v] > 0) {
            int res = dfs(graph, visited, v, min(flow, graph[u][v]));
            if (res > 0) {
                graph[u][v] -= res;
                graph[v][u] += res;
                return res;
            }
        }
    }
    return 0;
}

int ff(vii &graph) {
    int maxFlow = 0;
    vi visited(n + m + 2, 0);
    while (1) {
        int res = dfs(graph, visited, s, 1e8);
        if (!res) break;
        maxFlow += res;
        fill(visited.begin(), visited.end(), 0);
    }
    return maxFlow;
}

int main() {
    int test; cin >> test;
    while (test--) {
        string a, b; cin >> a >> b;
        n = a.size();
        m = b.size();
        s = 0;
        t = n + m + 1;
        vii graph(n + m + 2, vi(n + m + 2, 0));

        for (int i = 0; i < n; i++) {
            graph[s][i+1] = 1;
        }
        for (int i = 0; i < m; i++) {
            graph[i+n+1][t] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (abs(a[i] - b[j]) >= 3) {
                    graph[i+1][j+n+1] = 1;
                }
            }
        }

        cout << ff(graph) << '\n';
    }
    return 0;
}
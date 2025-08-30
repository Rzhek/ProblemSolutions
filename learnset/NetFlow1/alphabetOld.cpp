#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int n, m, s, t;

bool dfs(vii &graph, int u, vi &parent, vi &visited) {
    visited[u] = 1;
    for (int v = 0; v < n + m + 2; v++) {
        if (graph[u][v] > 0 && !visited[v]) {
            parent[v] = u;
            if (v == t) {
                return true;
            }
            if (dfs(graph, v, parent, visited)) return true;
        }
    }
    return false;
}

int ff(vii &graph) {
    int u, v;
    int maxFlow = 0;
    vi parent(n + m + 2, 0);
    vi visited(n + m + 2, 0);

    while (dfs(graph, s, parent, visited)) {
        int pathFlow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, graph[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
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

}
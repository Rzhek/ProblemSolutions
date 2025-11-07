#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using vi = vector<int>;

bool dfs(int a, int L, vector<vi> &g, vi &btoa, vi &A, vi &B)
{
    if (A[a] != L)
        return 0;
    A[a] = -1;
    for (int b : g[a])
        if (B[b] == L + 1)
        {
            B[b] = 0;
            if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
                return btoa[b] = a, 1;
        }
    return 0;
}
int hopcroftKarp(vector<vi> &g, vi &btoa)
{
    int res = 0;
    vi A(g.size()), B(btoa.size()), cur, next;
    for (;;)
    {
        fill(all(A), 0);
        fill(all(B), 0);
        cur.clear();
        for (int a : btoa)
            if (a != -1)
                A[a] = -1;
        rep(a, 0, sz(g)) if (A[a] == 0) cur.push_back(a);
        for (int lay = 1;; lay++)
        {
            bool islast = 0;
            next.clear();
            for (int a : cur)
                for (int b : g[a])
                {
                    if (btoa[b] == -1)
                    {
                        B[b] = lay;
                        islast = 1;
                    }
                    else if (btoa[b] != a && !B[b])
                    {
                        B[b] = lay;
                        next.push_back(btoa[b]);
                    }
                }
            if (islast)
                break;
            if (next.empty())
                return res;
            for (int a : next)
                A[a] = lay;
            cur.swap(next);
        }
        rep(a, 0, sz(g)) res += dfs(a, 0, g, btoa, A, B);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n * 2);
    vi match(n, -1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (hopcroftKarp(adj, match) != n)
        cout << "-1\n";
    else
    {
        vector<vi> res(n, vi(n));
        for (int u = 0; u < n; u++)
        {
            int v = match[u];
            // cout << u + 1 << " " << v + 1 << "\n";
            res[u][v] += 5000;
            res[v][u] += 5000;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
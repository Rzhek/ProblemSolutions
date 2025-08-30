#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vii;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define f first
#define s second
#define all(x) begin(x), end(x)

vector<pi> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
vvi grid;
vector<vii> par;
vvi visited;

int valid(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m; 
}

void dfs(int r, int c) {
    visited[r][c] = 1;
    vector<tuple<int, int, int>> order;
    for (auto [dr, dc] : dirs) {
        pi p1 = {r + dr, c + dc}, p2 = {r + 2 * dr, c + 2 * dc};
        if (!valid(p1.f, p1.s) || !valid(p2.f, p2.s)) continue;
        if (grid[p1.f][p1.s] == grid[p2.f][p2.s] && grid[p2.f][p2.s] != -2) {
            order.push_back({grid[p2.f][p2.s], p2.f, p2.s});
        }
    }
    sort(all(order));
    for (auto [val, newR, newC] : order) {
        if (!visited[newR][newC]) {
            par[newR][newC] = {r, c};
            dfs(newR, newC);
        }
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    grid = vvi(n, vi(m));
    par = vector<vii>(n, vii(m, {-1, -1}));
    visited = vvi(n, vi(m, 0));

    pi src;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] == -1)  {
                src.f = i; src.s = j;
            }
        }
    }

    pi tar; cin >> tar.f >> tar.s;
    tar.f--; tar.s--;
    dfs(src.f, src.s);

    vi res;
    while (par[tar.f][tar.s].f != -1) {
        res.push_back(grid[tar.f][tar.s]);
        tar = par[tar.f][tar.s];
    }


    if (res.size() == 0) {
        cout << "impossible" << '\n';
    } else {
        reverse(all(res));
        for (auto x : res) cout << x << " "; cout << '\n';
    }
    return 0;
}
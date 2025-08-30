#include <bits/stdc++.h>
using namespace std;

using vc = vector<char>;
using vcc = vector<vc>;
using vi = vector<int>;
using vii = vector<vi>;
using pi = pair<int, int>;
using iii = tuple<int, int, int>;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define f first
#define s second

int n, m;
vector<pi> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int valid(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

int bfs(int R, int C, vcc &grid, vii &path) {
    queue<iii> q;
    q.emplace(0, R, C);
    while (!q.empty()) {
        auto [w, r, c] = q.front(); q.pop();
        for (auto &[dr, dc] : dirs) {
            if (valid(r + dr, c + dc) && grid[r + dr][c + dc] != '#' && path[r + dr][c + dc] == 1e9) {
                path[r + dr][c + dc] = w + 1;
                if (grid[r + dr][c + dc] == 'B') return w + 1;
                q.emplace(w + 1, r + dr, c + dc);
            }
        } 
    }
    return -1;
}

vector<char> dfs(int r, int c, vii grid) {
    vector<char> res;
    while (grid[r][c]) {
        int cur = grid[r][c];
        if (valid(r - 1, c) && grid[r-1][c] == cur - 1) {
            r--;
            res.push_back('D');
        } else if (valid(r + 1, c) && grid[r+1][c] == cur - 1) {
            r++;
            res.push_back('U');
        } else if (valid(r, c - 1) && grid[r][c - 1] == cur - 1) {
            c--;
            res.push_back('R');
        } else if (valid(r, c + 1) && grid[r][c + 1] == cur - 1) {
            c++;
            res.push_back('L');
        }
    }
    reverse(res.begin(), res.end());
    return res;
}


int main() {
    // cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vcc grid(n, vc(m));
    vii path(n, vi(m, 1e9));
    pi start, end;
    rep(i, 0, n) rep(j, 0, m) {
        cin >> grid[i][j];
        if (grid[i][j] == 'A') start = {i, j};
        if (grid[i][j] == 'B') end = {i, j};
    }
    path[start.f][start.s] = 0;
    int res = bfs(start.f, start.s, grid, path);
    if (res == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << res << '\n';
    vector<char> resPath = dfs(end.f, end.s, path);
    for (char ch : resPath) cout << ch;
    cout << '\n';
    return 0;
}
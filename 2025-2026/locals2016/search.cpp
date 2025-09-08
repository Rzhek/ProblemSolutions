#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
vector<pii> dirs = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
string dir = "RDLU";

int main() {
    // cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for (auto &s : grid) cin >> s;

        int k; cin >> k;
        cout << "Word search puzzle #" << tt << ":\n";
        while (k--) {
            string s; cin >> s;
            int done = 0;
            for (int startR = 0; !done && startR < n; startR++) {
                for (int startC = 0; !done && startC < m; startC++) {
                    for (int idk = 0; !done && idk < 4; idk++) {
                        auto [dr, dc] = dirs[idk];
                        int works = 1;
                        for (int l = 0; works && l < s.size(); l++) {
                            int r = startR + (dr * l);
                            int c = startC + (dc * l);
                            r = (r + n * 100) % n;
                            c = (c + m * 100) % m;
                            // cout << r << " " << c << "\n";
                            works &= grid[r][c] == s[l];
                        }
                        if (works) {
                            done = 1;
                            cout << dir[idk] << " " << startR + 1 << " " << startC + 1 << " " << s << "\n";
                        }
                    }
                }
            }
            assert(done);
            cout << "\n";
        }
    }
}
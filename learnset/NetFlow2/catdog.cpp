#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) x.begin(), x.end()

using vi = vector<int>;

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
    if (btoa[j] == -1) return 1;
    vis[j] = 1; int di = btoa[j];
    for (int e : g[di])
        if (!vis[e] && find(e, g, btoa, vis)) {
            btoa[e] = di;
            return 1;
        }
    return 0;
}

int dfsMatching(vector<vi>& g, vi& btoa) {
    vi vis;
    rep(i, 0, sz(g)) {
        vis.assign(sz(btoa), 0);
        for (int j : g[i])
            if (find(j, g, btoa, vis)) {
                btoa[j] = i;
                break;
            }
    }
    return sz(btoa) - (int)count(all(btoa), -1);
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int c, d, n; cin >> c >> d >> n;
        vector<vi> forCat(c), forDog(d), againstCat(c), againstDog(d);
        int catppl = 0, dogppl = 0;
        int s = n, t = n + 1;

        for (int i = 0; i < n; i++) {
            string s1, s2; cin >> s1 >> s2;
            int first = stoi(s1.substr(1));
            int second = stoi(s2.substr(1));

            if (s1[0] == 'C') {
                forCat[first-1].push_back(catppl);
                againstDog[second-1].push_back(catppl++);
            }
            else {
                forDog[first-1].push_back(dogppl);
                againstCat[second-1].push_back(dogppl++);
            }
        }

        vector<vi> g(catppl);
        vi res(dogppl, -1);

        for (int cat = 0; cat < c; cat++) {
            for (int forcat : forCat[cat]) {
                for (int againstcat : againstCat[cat]) {
                    g[forcat].push_back(againstcat);
                }
            }
        }

        for (int dog = 0; dog < d; dog++) {
            for (int fordog : forDog[dog]) {
                for (int againstdog : againstDog[dog]) {
                    g[againstdog].push_back(fordog);
                }
            }
        }

        cout << n - dfsMatching(g, res) << "\n";

        // for (int i = 0; i < res.size(); i++) {
        //     cout << i << ": " << res[i] << "\n";
        // }
        // cout << "\n";

    }
}
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;

struct FT {
    vector<ll> s;
    FT(int n): s(n) {}
    void update(int pos, ll dif) {
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) {
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

struct FT2 {
    vector<vi> ys; vector<FT> ft;
    FT2(int limx): ys(limx) {}
    void fakeUpdate(int x, int y) {
        for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
    }
    void init() {
        for (vi& v : ys) {
            sort(all(v));
            v.erase(unique(v.begin(), v.end()), v.end());
            ft.emplace_back(sz(v));
        }
    }
    int ind(int x, int y) {
        return (int)(lower_bound(all(ys[x]), y) - ys[x].begin());
    }
    void update(int x, int y, ll dif) {
        for (; x < sz(ys); x |= x + 1)
            ft[x].update(ind(x, y), dif);
    }
    ll query(int x, int y) {
        ll sum = 0;
        for (; x; x &= x - 1)
            sum += ft[x-1].query(ind(x-1, y));
        return sum;
    }
    ll query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    FT2 ft2(n+5);
    vector<vi> queries;
    vector<vi> grid(n+5, vi(n+5));
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            char ch; cin >> ch;
            if (ch == '*') ft2.fakeUpdate(r, c), queries.push_back({r, c});
        }
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int r, c; cin >> r >> c;
            ft2.fakeUpdate(r, c);
            queries.push_back({r, c});
        } else {
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            queries.push_back({r1, c1, r2, c2});
        }
    }

    ft2.init();
    for (auto v : queries) {
        if (v.size() == 2) {
            if (grid[v[0]][v[1]]) ft2.update(v[0], v[1], -1);
            else ft2.update(v[0], v[1], 1);
            grid[v[0]][v[1]] ^= 1;
        } else {
            cout << ft2.query(v[0]+1, v[1]+1, v[2]+1, v[3]+1) << "\n";
        }
    }

}
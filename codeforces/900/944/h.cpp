#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n';
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values;
    TwoSat(int n = 0) : N(n), gr(2 * n) {}
    int addVar() {
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }
    void either(int f, int j) {
        f = max(2 * f, -1 -2 * f);
        j = max(2 * j, -1 -2 * j);
        gr[f].push_back(j ^ 1);
        gr[j].push_back(f ^ 1);
    }
    void setValue(int x) { either(x, x); }
    void atMostOne(const vi& li) {
        if (sz(li) <= 1) return;
        int cur = ~li[0];
        rep(i, 2, sz(li)) {
            int next = addVar();
            either(cur, ~li[i]);
            either(cur, next);
            either(~li[i], next);
            cur = ~next;
        }
        either(cur, ~li[1]);
    }
    vi val, comp, z;
    int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x;
        z.push_back(i);
        for (int e : gr[i])
            if (!comp[e]) low = min(low, val[e] ?:dfs(e));
        if (low == val[i]) do {
            x = z.back(), z.pop_back();
            comp[x] = low;
            if (values[x >> 1] == -1) values[x >> 1] = x & 1;
        } while (x != i);
        return val[i] = low;
    }
    bool solve() {
        values.assign(N, -1), val.assign(2 * N, 0), comp = val;
        rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
        rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
        return 1;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        TwoSat ts(n);
        vvi vals(n, vi(3));
        forn(j, 3) {
            forn(i, n) {
                cin >> vals[i][j];
                if (vals[i][j] < 0) {
                    vals[i][j]++;
                    vals[i][j] = -vals[i][j];
                    vals[i][j] = ~vals[i][j];
                } else {
                    vals[i][j]--;
                }
            }
        }

        forn(i, n) {
            // printArr(vals[i]);
            ts.atMostOne(vals[i]);
        }

        if (ts.solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


    // TwoSat ts(4);
    // int a = 0, b = 1, c = 2, d = 3;

    // // a = f, b = t, c = t, d = f
    // ts.atMostOne({a, ~d, a}); // f + t + f
    // ts.atMostOne({~b, d, b}); // f + f + t
    // ts.atMostOne({~c, ~a, ~b}); // f + t + f
    // ts.atMostOne({~b, ~c, d}); // f + f + f
    
    // cout << ts.solve() << '\n';

    // for (int i = 0; i < 4; i++) cout << ts.values[i] << " ";
    // cout << '\n';

    // TwoSat ts(2);
    // int a = 0, b = 1;
    // ts.atMostOne({a, ~a, b});
    // ts.atMostOne({b, ~b, ~b});

    // cout << ts.solve() << '\n';

    // for (int i = 0; i < 4; i++) cout << ts.values[i] << " ";
    // cout << '\n';

    // TwoSat ts(5);
    // int a = 0, b = 1, c = 2, d = 3, e = 4;
    // ts.atMostOne({a, ~b, c});
    // ts.atMostOne({b, c, ~e});
    // ts.atMostOne({c, ~d, a});
    // ts.atMostOne({d, ~e, b});
    // ts.atMostOne({e, ~a, b});


    // cout << ts.solve() << '\n';

    // for (int i = 0; i < 5; i++) cout << ts.values[i] << " ";
    // cout << '\n';

    return 0;
}
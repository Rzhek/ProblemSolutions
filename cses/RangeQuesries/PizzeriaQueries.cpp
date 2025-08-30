#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
#define f first
#define s second

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using iii = tuple<int, int, int>;

const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

template <class T, T defVal, T (*op)(T a, T b)>
struct SegTree {
    int n;
    vector<T> vals;
    SegTree() {}
    SegTree(int n) : n(n), vals(4*n, defVal) {}
    
    void update(int pos, T v) { update(pos, v, 1, 1, n); }
    void update(int pos, T v, int i, int l, int r) {
        if (l == r) {
            vals[i] = v;
            return;
        }
        int m = (l+r) / 2;
        if (pos <= m) update(pos, v, i * 2, l, m);
        else update(pos, v, i * 2 + 1, m + 1, r);
        vals[i] = op(vals[i*2], vals[i*2+1]);
    }

    T query(int l, int r) { return query(l, r, 1, 1, n); }
    T query(int lo, int hi, int i, int l, int r) {
        if (lo <= l && r <= hi) return vals[i];
        if (hi < l || lo > r) return defVal;
        int m = (l+r) / 2;
        return op(query(lo, hi, i*2, l, m), query(lo, hi, i*2+1, m+1, r));
    }
};

int op(int a, int b) { return min(a, b); }

const int maxn = 2e5+5;
int n, q, p[maxn];
SegTree<int, (int)1e9, op> down, up;

void pull(int i) {
    down.update(i, p[i] - i);
    up.update(i, p[i] + i);
}

int main() {
    cin >> n >> q;
    forn (i, n) cin >> p[i+1];

    down = up = SegTree<int, (int)1e9, op>(n);
    forn (i, n) pull(i+1);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, x; cin >> k >> x;
            p[k] = x;
            pull(k);
        } else {
            int k; cin >> k;
            int D = down.query(1, k) + k;
            int U = up.query(k, n) - k;
            cout << min(D, U) << "\n";
        }
    }
}
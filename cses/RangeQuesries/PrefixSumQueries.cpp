#pragma GCC optimize("O3")
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

// Regular SegTree
template <class T>
struct Tree { // [l, r]
    int l, r, m;
    T full, best;
    Tree *left, *right;
    
    Tree (vector<T> &vals, int l, int r) : l(l), r(r), m((l+r)/2) {
        if (l == r) {
            full = vals[l];
            best = max(0ll, full);
            left = right = nullptr;
        } else {
            left = new Tree(vals, l, m);
            right = new Tree(vals, m+1, r);
            full = left->full + right->full;
            best = max(left->best, left->full + right->best);
        }
    }

    pair<T, T> query(int lo, int hi) {
        if (lo <= l && r <= hi) return {full, best};
        if (l > hi || r < lo) return {0, 0};
        pair<T, T> a = left->query(lo, hi);
        pair<T, T> b = right->query(lo, hi);
        return {a.f + b.f, max(a.s, a.f + b.s)};
    }

    void update(int pos, T v) {
        if (l == r) {
            assert(l == pos);
            full = v;
            best = max(0ll, v);
            return;
        }
        if (pos <= (l + r) / 2) left->update(pos, v);
        else right->update(pos, v); 
        full = left->full + right->full;
        best = max(left->best, left->full + right->best);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vl nums(n);
    forn (i, n) cin >> nums[i];
    Tree<ll> ST(nums, 0, n - 1);

    while (q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            ST.update(a-1, b);
        } else {
            cout << ST.query(a-1, b-1).s << "\n";
        }
    }
    return 0;
}
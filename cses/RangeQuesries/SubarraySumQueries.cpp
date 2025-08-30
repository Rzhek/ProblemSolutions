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
    T le, ri, full, best;
    Tree *left, *right;
    
    Tree (vector<T> &vals, int l, int r) : l(l), r(r), m((l+r)/2) {
        if (l == r) {
            full = vals[l];
            le = ri = full;
            best = max((T)0, full);
            left = right = nullptr;
        } else {
            left = new Tree(vals, l, m);
            right = new Tree(vals, m+1, r);
            full = left->full + right->full;
            le = max(left->le, left->full + right->le);
            ri = min(right->ri, right->full + left->ri);
            best = max({le, ri, left->ri + right->le});
        }
    }

    T find(int lo, int hi) { 
        return get<3>(query(lo, hi));
    }
    tuple<T, T, T, T> query(int lo, int hi) {
        if (lo <= l && r <= hi) return {full, le, ri, best};
        if (l > hi || r < lo) return {(T)0, (T)0, (T)0, (T)0};
        auto [a_full, a_le, a_ri, a_best] = left->query(lo, hi);
        auto [b_full, b_le, b_ri, b_best] = left->query(lo, hi);
        // return {a.f + b.f, max(a.s, a.f + b.s)};
        return {
            a_full + b_full, 
            max(a_le, a_full + b_le), 
            max(b_ri, b_full + a_ri), 
            max({max(a_le, a_full + b_le), max(b_ri, b_full + a_ri), a_ri + b_le})
        };
    }

    void update(int pos, T v) {
        if (l == r) {
            assert(l == pos);
            full = v;
            le = ri = max((T)0, full);
            return;
        }
        if (pos <= (l + r) / 2) left->update(pos, v);
        else right->update(pos, v); 
        full = left->full + right->full;
        le = max(left->le, left->full + right->le);
        ri = min(right->ri, right->full + left->ri);
    }

    void print() {
        cout << "(" << l << ", " << r << ")" << ": " << full << " " << le << " " << ri << " " << best << "\n";
        if (l == r) return;
        left->print();
        right->print();
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vl nums(n);
    forn (i, n) cin >> nums[i];
    Tree<ll> ST(nums, 0, n - 1);

    cout << ST.find(0, 0) << "\n";

    ST.print();
    // cout << "\n";

    // while (q--) {
    //     int k, a; cin >> k >> a;
    //     ST.update(k-1, a);
    //     cout << ST.find(0, n-1) << "\n";
    // }
    return 0;
}
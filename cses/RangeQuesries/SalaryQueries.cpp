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

template <class T, T defVal, T(*op)(T, T), T(*upd)(T, T)>
struct Tree { // [l, r]
    int l, r, m;
    T val;
    Tree *left, *right;
    
    Tree (vi &vals, int l, int r) : l(l), r(r), m((l+r)/2) {
        if (l == r) {
            val = vals[l];
            left = right = nullptr;
        } else {
            left = new Tree(vals, l, m);
            right = new Tree(vals, m, r);
            val = op(left->val, right->val);
        }
    }

    Tree (int l, int r) : l(l), r(r), m((l+r)/2) {
        if (l == r) {
            val = defVal;
            left = right = nullptr;
        } else {
            left = new Tree(l, m);
            right = new Tree(m + 1, r);
            val = op(left->val, left->val);
        }
    }

    int query(int lo, int hi) {
        if (lo <= l && r <= hi) return val;
        if (l > hi || r < lo) return 0;
        return op(left->query(lo, hi), right->query(lo, hi));
    }

    void update(int pos, T v) {
        if (l == r) {
            assert(l == pos);
            val = upd(val, v);
            return;
        }
        if (pos <= (l + r) / 2) left->update(pos, v);
        else right->update(pos, v); 
        val = op(left->val, right->val);
    }
};

int op(int a, int b) { return a + b; }
int upd(int a, int b) { return a + b; }

int getInd(int x, const vi &vals) {
    int ind = lower_bound(all(vals), x) - vals.begin();
    assert(ind < vals.size() && vals[ind] == x);
    return ind;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vi arr(n), vals;
    forn (i, n) cin >> arr[i];
    vals = arr;

    vector<iii> rec;
    forn (i, q) {
        char t; cin >> t;
        int a, b; cin >> a >> b;
        rec.emplace_back(t == '?', a, b);
        if (t == '?') vals.push_back(a);
        vals.push_back(b);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    vals.size();
    Tree<int, 0, op, upd> ST(0, vals.size());
    forn (i, n) ST.update(getInd(arr[i], vals), 1); 

    for (auto &[t, a, b] : rec) {
        if (t == 0) {
            a--;
            ST.update(getInd(arr[a], vals), -1);
            arr[a] = b;
            ST.update(getInd(arr[a], vals), 1);
        } else {
            cout << ST.query(getInd(a, vals), getInd(b, vals)) << "\n";
        }
    }
    return 0;
}
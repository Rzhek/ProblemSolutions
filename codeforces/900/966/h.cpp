#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

const int maxa = 5e6;

// * Regular SegTree
template <class T, T defVal, T(*op)(T, T), T(*upd)(T, T)>
struct Tree { // [l, r]
    int l, r, m;
    T val;
    Tree *left, *right;
    
    Tree (vector<T> &vals, int l, int r) : l(l), r(r), m((l+r)/2) {
        if (l == r) {
            val = vals[l];
            left = right = nullptr;
        } else {
            left = new Tree(vals, l, m);
            right = new Tree(vals, m+1, r);
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
        if (l > hi || r < lo) return defVal;
        return op(left->query(lo, hi), right->query(lo, hi));
    }

    void update(int pos, T v) {
        if (l == r) {
            assert(l == pos);
            val = upd(val, v);
            return;
        }
        if (pos <= m) left->update(pos, v);
        else right->update(pos, v); 
        val = op(left->val, right->val);
    }
};
// Example for sum queries
int op(int a, int b) { return min(a, b); }
int upd(int a, int b) { return b; }
// Use: Tree<int, 0, op, upd>  ST(0, n);

Tree<int, maxa, op, upd> ST(0, maxa);
set<int> nums = {0, maxa};
multiset<pii> gaps = {{maxa-1, 0}};

void add(int b) {
    auto it = nums.upper_bound(b);
    assert(it != nums.end());
    assert(*it != b);
    int c = *it;
    int a = *(--it);
    nums.insert(b);

    gaps.erase({c - a - 1, a});
    gaps.insert({c - b - 1, b});
    gaps.insert({b - a - 1, a});
    
    // find next index with gap c - a - 1
    auto it2 = gaps.lower_bound({c - a - 1, 0});
    if (it2->first != c - a - 1) {
        // we removed the last such gap
        // cerr << "we removed a gap " << c - a - 1 << "\n";
        ST.update(c - a - 1, maxa);
    } else {
        // cerr << "replacing a gap " << c - a - 1 << " with index " << it2->second << "\n";
        ST.update(c - a - 1, it2->second);
    }

    it2 = gaps.lower_bound({c - b - 1, 0});
    if (b == it2->second) {
        // cerr << "a gap of " << c - b - 1 << " now has index " << b << "\n";
        ST.update(c - b - 1, b);
    }

    it2 = gaps.lower_bound({b - a - 1, 0});
    if (a == it2->second) {
        // cerr << "a gap of " << b - a - 1 << " now has index " << a << "\n";
        ST.update(b - a - 1, a);
    }
}

void remove(int b) {
    auto it = nums.find(b);
    it--;
    int a = *it;
    it++; it++;
    int c = *it;
    nums.erase(b);

    gaps.erase({b - a - 1, a});
    gaps.erase({c - b - 1, b});
    gaps.insert({c - a - 1, a});

    auto it2 = gaps.lower_bound({c - a - 1, 0});
    if (it2->s == a) {
        ST.update(c - a - 1, a);
    }

    it2 = gaps.lower_bound({c - b - 1, 0});
    if (it2->f == c - b - 1) {
        ST.update(c - b - 1, it2->s);
    } else {
        ST.update(c - b - 1, maxa);
    }

    it2 = gaps.lower_bound({b - a - 1, 0});
    if (it2->f == b - a - 1) {
        ST.update(b - a - 1, it2->s);
    } else {
        ST.update(b - a - 1, maxa);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        nums = {0, maxa};
        gaps = {{maxa-1, 0}};
        ST.update(maxa - 1, 0);

        int n; cin >> n;
        forn (i, n) {
            int a; cin >> a;
            add(a);
        }

        int q; cin >> q;
        while (q--) {
            char type; cin >> type;
            int x; cin >> x;
            if (type == '+') {
                add(x);
            } else if (type == '-') {
                remove(x);
            } else {
                x = gaps.lower_bound({x, 0})->first;
                cout << ST.query(x, maxa) + 1 << " ";
            }
        }
        cout << "\n";

        for (auto [gap, ind] : gaps) {
            ST.update(gap, maxa);
        }

        // add(1);
        // add(2);
        // printArr(nums);
        // for (auto [x, y] : gaps) {
        //     cout << x << " " << y << " | ";
        // }
        // cout << "\n";
        // cout << ST.query(1, maxa) + 1 << "\n"; 
        

    }
    return 0;
}
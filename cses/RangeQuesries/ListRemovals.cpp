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

struct Node { // [l, r]
    int l, r;
    ll val;
    Node *left, *right;
    
    Node(vl &vals, int l, int r) : l(l), r(r) {
        if (l == r) {
            val = vals[l];
            left = right = nullptr;
        } else {
            int m = (l + r) / 2;
            left = new Node(vals, l, m);
            right = new Node(vals, m + 1, r);
            val = left->val + right->val;
        }
    }

    Node(int l, int r, int v) : l(l), r(r) {
        if (l == r) {
            val = v;
            left = right = nullptr;
        } else {
            int m = (l + r) / 2;
            left = new Node(l, m, v);
            right = new Node(m + 1, r, v);
            val = left->val + right->val;
        }
    }

    ll query(int lo, int hi) {
        if (lo <= l && r <= hi) return val;
        if (l > hi || r < lo) return 0;
        return left->query(lo, hi) + right->query(lo, hi);
    }

    void update(int pos, int v) {
        if (l == r) {
            assert(l == pos);
            val = v;
            return;
        }
        if (pos <= (l + r) / 2) left->update(pos, v);
        else right->update(pos, v); 
        val = left->val + right->val;
    }

    void print() {
        if (l == r) {
            cout << val << " ";
            return;
        }
        left->print();
        right->print();
    }

    int find(int v) {
        if (l == r) {
            // assert(val == 1 && v == 1);
            // val = 0;
            return l;
        }
        if (left->val >= v) {
            return left->find(v);
        } else {
            return right->find(v - left->val);
        }
        // val = left->val + right->val;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    Node ST(0, n-1, 1);

    vi nums(n, 0);
    forn (i, n) cin >> nums[i];
    forn (i, n) {
        int a; cin >> a;
        int res = ST.find(a);
        
        // cout << res << ": ";
        // ST.print();
        ST.update(res, 0);
        // cout << "\n";
        cout << nums[res] << " ";
    }
    cout << "\n";


    return 0;
}
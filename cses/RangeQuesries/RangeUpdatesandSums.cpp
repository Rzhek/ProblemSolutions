#include <bits/stdc++.h>
using namespace std;
 
#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
#define forn(i, n) for (int i = 0; i < n; ++i)
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
const int mod2inv = 500000004;
const long double EPS = 1e-9;
 
struct Node {
    int l, r, m, len;
    ll val, prop;
    Node *left, *right;
    // bool wasReset;
    
    Node(int l, int r) : l(l), r(r), m((l+r)/2), len(r-l), val(0), prop(0), left(0), right(0) {}
 
    Node(int l, int r, vi& nums) : l(l), r(r), m((l+r)/2), len(r-l), prop(0), left(0), right(0) {
        if (l + 1 < r) {
            left = new Node(l, m, nums);
            right = new Node(m, r, nums);
            val = left->val + right->val;
        } else {
            left = right = nullptr;
            val = nums[l];
        }
    }
    
 
    ll query(int lo, int hi) {
        if (lo >= r || hi <= l) return 0;
        if (lo <= l && r <= hi) return val + prop * len;
 
        if (!left) {
            return (val + prop * len) / len * (min(hi, r) - max(l, lo));
            // left = new Node(l, m);
            // right = new Node(m, r);
            // left->val = val / len * left->len;
            // right->val = val / len * right->len;
        }
        left->prop += prop;
        right->prop += prop;
        val += prop * len;
        prop = 0;
 
        return left->query(lo, hi) + right->query(lo, hi);
    }
 
    void set(int lo, int hi, ll x) {
        if (lo >= r || hi <= l) return;
        if (lo <= l && r <= hi) {
            val = x * len;
            prop = 0;
            left = right = nullptr;
            return;
        }
 
        if (!left) {
            left = new Node(l, m);
            right = new Node(m, r);
            left->val = val / len * left->len;
            right->val = val / len * right->len;
        }
        left->prop += prop;
        right->prop += prop;
        prop = 0;
 
        left->set(lo, hi, x);
        right->set(lo, hi, x);
 
        val = left->val + left->prop * left->len + right->val + right->prop * right->len;
    }
 
    void increase(int lo, int hi, ll x) {
        if (lo >= r || hi <= l) return;
        if (lo <= l && r <= hi) {
            prop += x;
            return;
        }
        
        if (!left) {
            left = new Node(l, m);
            right = new Node(m, r);
            left->val = val / len * left->len;
            right->val = val / len * right->len;
        }
        left->prop += prop;
        right->prop += prop;
        prop = 0;
 
        left->increase(lo, hi, x);
        right->increase(lo, hi, x);
        
        val = left->val + left->prop * left->len + right->val + right->prop * right->len;
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vi nums(n);
    for (auto &x : nums) cin >> x;
    Node ST(0, n, nums);
 
    while (q--) {
        int type, a, b, x; cin >> type >> a >> b;
        if (type == 1) {
            cin >> x;
            ST.increase(a-1, b, x);
        } else if (type == 2) {
            cin >> x;
            ST.set(a-1, b, x);
        } else {
            cout << ST.query(a-1, b) << "\n";
        }
    }
 
 
    // Node ST(0, 100);
 
    // cout << ST.query(0, 100) << "\n";
    // ST.increase(25, 75, 10);
    // ST.increase(30, 40, 5);
    // cout << ST.query(30, 40) << "\n";
    
    // cout << ST.left->val << "\n";
}
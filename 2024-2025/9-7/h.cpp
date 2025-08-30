#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
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

struct Tree {
    // A node that records how many line segments completely cover range [l, r)
    // deltaProp represents that children of this node have deltaProp more lines
    int l, r, m, numSegments, deltaProp, value;
    Tree *left, *right;
    Tree (int a, int b) : l(a), r(b), m((a+b)/2), numSegments(0), left(nullptr), right(nullptr), deltaProp(0), value(0) {}

    void propagate(int val) {
        numSegments += val;
        if (left && right) deltaProp += val;
        if (numSegments > 0) value = r - l;
        else if (left && right) {
            if (deltaProp) {
                left->propagate(deltaProp);
                right->propagate(deltaProp);
            }
            deltaProp = 0;
            value = left->value + right->value;
        } else {
            value = 0;
        }
        // if (l == 1 && r == 2) cout << numSegments << " " << value << " WTFYTSAFYU\n";
    }

    void update(int lo, int hi, int val) {// increase values for [lo, hi) by val
        if (hi <= l || r <= lo) return; // no overlap
        // cout << lo << " " << hi << " | " << l << " " << r << "\n";
        if (lo <= l && r <= hi) { // total overlap
            numSegments += val;
            if (left && right) {
                deltaProp += val;
            }
            if (numSegments > 0) value = r - l;
            else if (left && right) {
                left->propagate(deltaProp);
                right->propagate(deltaProp);
                deltaProp = 0;
                value = left->value + right->value;
            } else {
                value = 0;
            }
            return;
        }
        assert(l != r);
        if (!left && !right) {
            left = new Tree(l, m);
            right = new Tree(m, r);
            assert(deltaProp == 0);
            left->propagate(numSegments);
            right->propagate(numSegments);
        }
        if (deltaProp) {
            left->propagate(deltaProp);
            right->propagate(deltaProp);
            deltaProp = 0;
        }  
        left->update(lo, hi, val);
        right->update(lo, hi, val);
        value = left->value + right->value;
        if (numSegments > 0) value = r - l;
    }
};

void print(Tree *node) {
    cout << "[" << node->l << ", " << node->r << "): segs: " << node->numSegments << " value: " << node->value << " prop: " << node->deltaProp << "\n"; 
} 

const double mult = sqrt(2);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(10);
    int q, n; cin >> q >> n;
    Tree ST(0, n);
    set<pii> pts;
    while (q--) {
        int x, y; cin >> x >> y;
        if (pts.count({x, y})) {
            // cout << "unmark range " << x - y << " " << x + y << "\n";
            pts.erase({x, y});
            ST.update(x - y, x + y, -1);
        } else {
            // cout << "mark range " << x - y << " " << x + y << "\n";
            pts.insert({x, y});
            ST.update(x - y, x + y, 1);
        }
        cout << ST.value * mult << "\n";
        // if (ST.left->left) print(ST.left->left);
    }

    
    return 0;
}
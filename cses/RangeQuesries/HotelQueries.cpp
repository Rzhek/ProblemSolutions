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
    int l, r, val;
    Node *left, *right;
    
    Node(vi &vals, int l, int r) {
        this->l = l;
        this->r = r;
        if (l == r) {
            val = vals[l];
            left = right = nullptr;
        } else {
            int m = (l + r) / 2;
            left = new Node(vals, l, m);
            right = new Node(vals, m + 1, r);
            val = max(left->val, right->val);
        }
    }

    int assign(int v) {
        if (val < v) return 0;
        if (l == r) {
            val -= v;
            return l + 1;
        }
        int res = (left->val >= v) ? left->assign(v) : right->assign(v);
        val = max(left->val, right->val);
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vi nums(n);
    forn (i, n) cin >> nums[i];
    Node *ST = new Node(nums, 0, n - 1);


    while (q--) {
        int v; cin >> v;
        cout << ST->assign(v) << " ";
    } 
    cout << "\n";
    return 0;
}
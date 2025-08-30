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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int getMedian(Tree<pii> &tree, int k) {
    return (*tree.find_by_order(k / 2 - (1 - k & 1))).f;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vi nums(n);
    forn (i, n) cin >> nums[i];

    Tree<pii> tree;
    forn (i, k) tree.insert({nums[i], i});

    cout << getMedian(tree, k) << " ";

    for (int i = k; i < n; i++) {
        tree.erase({nums[i-k], i-k});
        tree.insert({nums[i], i});
        cout << getMedian(tree, k) << " ";
    }

    cout << "\n";
    return 0;
}
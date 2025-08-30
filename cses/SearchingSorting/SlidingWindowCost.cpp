#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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


template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vi nums(n); 
    forn (i, n) cin >> nums[i];

    Tree<pii> set;

    forn (i, k) set.insert({nums[i], i});
    ll cost = 0;
    int m = k / 2 - 1 + k % 2;
    int curm = set.find_by_order(m)->f;
    for (auto [x, ind] : set) {
        cost += abs(x - curm);
    }

    for (int i = k;; i++) {
        cout << cost << " ";
        if (i == n) break;

        int prev = nums[i-k], next = nums[i];
        cost -= abs(prev - curm);
        cost += abs(next - curm);
        set.erase({prev, i-k});
        set.insert({next, i});
        int newm = set.find_by_order(m)->f;

        if (newm == curm) continue;
        if (newm < curm) {
            cost -= (ll)abs(curm - newm) * (m + 1);
            cost += (ll)abs(curm - newm) * (k - m - 1);
        } else {
            cost += (ll)abs(curm - newm) * (m);
            cost -= (ll)abs(curm - newm) * (k - m);
        }
        curm = newm;
    }


    return 0;
}
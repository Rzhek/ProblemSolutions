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

// * Fenwick Tree | Binary Index Tree (BIT)
// 956D
const int maxn = 1e5+5; // or whatever the upper bound is
ll fen[maxn];
int ind[maxn];
inline void add(int p, int val) { // make sure to convert to 1 base index
    for (; p < maxn; p += p&-p) fen[p] += val;
}
inline ll get(int p) { // inclusive [1, p]
    ll sum = 0;
    for (; p; p -= p&-p) sum += fen[p];
    return sum;
}
inline ll get(int a, int b) { // [a, b]
    return max(0ll, get(b) - get(a - 1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(fen, 0, sizeof(fen));
    int n;
    for (cin >> n; n != 0; cin >> n) {
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            ind[a] = i;
            add(i, 1);
        }

        ll res = 0;
        int last = 1;
        for (int i = 1; i <= n; i++) {
            ll left, right;
            if (last < ind[i]) {
                left = get(last, ind[i]);
                right = get(1, last) + get(ind[i], n);
            } else {
                left = get(1, ind[i]) + get(last, n);
                right = get(ind[i], last);
            }
            res += min(left, right);
            add(ind[i], -1);
            last = ind[i];
        }
        cout << res << "\n";
    }
    return 0;
}
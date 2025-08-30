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

const int maxn = 2e5+5; 
int fen[maxn], a[maxn];
vi lvl_up[maxn], ind[maxn], rem;

inline void add(int p, int val) {
    for (p++; p < maxn; p += p&-p) fen[p] += val;
}
inline int get(int p) { // inclusive
    int sum = 0;
    for (; p; p -= p&-p) sum += fen[p];
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    forn (i, n) cin >> a[i], ind[a[i]].pb(i), add(i, 1);

    for (int i = 1; i <= n; i++) {
        lvl_up[i].pb(0);
        rem.pb(i);
    }

    for (int lvl = 1; lvl <= n; lvl++) {
        vi nrem;
        for (int x : rem) {
            int cur = lvl_up[x].back();
            int lo = cur, hi = n + 1;

            while (hi - lo > 1) {
                int m = (lo + hi) / 2;
                if (get(m) - get(cur) >= x) hi = m;
                else lo = m;
            }

            if (hi <= n) lvl_up[x].pb(hi), nrem.pb(x);
        }
        for (int i : ind[lvl]) add(i, -1);
        rem = nrem;
    }

    while (q--) {
        int i, x; cin >> i >> x;
        i--;
        if (lvl_up[x].size() <= a[i] || lvl_up[x][a[i]] > i) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
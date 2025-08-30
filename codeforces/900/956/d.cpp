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

const int maxn = 2e5+5;
int n, a[maxn], b[maxn], inds[maxn], fen[maxn];

inline void add(int p, int val) {
    for (; p < maxn; p += p&-p) fen[p] += val;
}
inline int get(int p) {
    int sum = 0;
    for (; p; p -= p&-p) sum += fen[p];
    return sum;
}

inline void construct(vi &vals) {
    int n = vals.size();
    fen[0] = 0;
    for (int i = 1; i <= n; i++) fen[i] = vals[i-1];
    for (int i = 1; i <= n; i++) {
        int j = i + (i&-i);
        if (j <= n) fen[j] = fen[j] + fen[i];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(inds, -1, sizeof(inds));
    // was changed to 1 base index entirely
    // to see the original go to CF submissions

    tests {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], inds[a[i]] = i;
        for (int i = 1; i <= n; i++) cin >> b[i], b[i] = inds[b[i]];
        for (int i = 1; i <= n; i++) inds[a[i]] = -1;

        int flag = 1;
        for (int i = 1; i <= n; i++) flag &= (b[i] != -1);

        if (!flag) {
            cout << "NO\n";
            continue;
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i-1 - get(b[i]);
            add(b[i], 1);
        }
        for (int i = 1; i <= n; i++) {
            add(b[i], -1);
        }
        if (sum % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
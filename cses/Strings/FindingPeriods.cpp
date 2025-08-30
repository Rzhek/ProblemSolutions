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

typedef uint64_t ull;
typedef ull H;

static const H C = (ll)1e11 + 3;
struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string &str) : ha(sz(str) + 1), pw(ha) {
        pw[0] = 1;
        rep(i, 0, sz(str)) ha[i + 1] = ha[i] * C + str[i],
                            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) {
        return ha[b] - ha[a] * pw[b - a];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    HashInterval hash(s);

    for (int len = 1; len <= sz(s); len++) {
        int works = 1, i = 0;
        for (; works && i * len < sz(s) - len; i++) {
            works &= hash.hashInterval(0, len) == hash.hashInterval(i * len, i * len + len);
        }

        works &= hash.hashInterval(i * len, sz(s)) == hash.hashInterval(0, (sz(s) % len) == 0 ? len : sz(s) % len);
        if (works) cout << len << " ";
    }
    cout << "\n";
}
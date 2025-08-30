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


int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, c, k; cin >> n >> c >> k;
        string s; cin >> s;
        vi bad(1 << c, 0), cnt(c, 0);

        int mask = 0;
        forn (i, k - 1) {
            int ch = s[i] - 'A';
            if (!cnt[ch]) mask += 1 << ch;
            cnt[ch]++;
        }

        for (int i = k - 1; i < n; i++) {
            int ch = s[i] - 'A';
            if (!cnt[ch]) mask += 1 << ch;
            cnt[ch]++;

            bad[mask] = 1;

            ch = s[i-k+1] - 'A';
            cnt[ch]--;
            if (!cnt[ch]) mask -= 1 << ch;
        }

        bad[1 << (s[n-1] - 'A')] = 1;

        forn (i, 1 << c) {
            if (bad[i]) {
                forn (j, c) bad[i | (1 << j)] = 1;
            }
        }

        int res = c;
        forn (i, 1 << c) {
            if (!bad[i]) {
                res = min(res, c - __builtin_popcount(i));
            }
        }

        cout << res << "\n";
    }
    return 0;
}
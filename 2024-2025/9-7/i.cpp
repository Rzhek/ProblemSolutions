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

int n, k;
string s, res;
bitset<2501> dp[40][40][400];

int solve(int i, int ns, int nas, int nacs) {
    // cerr << i << " " << ns << " " << nas << " " << nacs << "\n";
    if (nacs > k) return 0;
    if (i == n) return nacs == k;
    if (dp[i][ns][nas][nacs]) return 0;
    dp[i][ns][nas][nacs] = 1;

    if (s[i] == '?' || s[i] == 'N') {
        if (solve(i+1, ns+1, nas, nacs)) {
            res += 'N';
            return 1;
        }
    }
    if (s[i] == '?' || s[i] == 'A') {
        if (solve(i+1, ns, nas+ns, nacs)) {
            res += 'A';
            return 1;
        }
    }
    if (s[i] == '?' || s[i] == 'C') {
        if (solve(i+1, ns, nas, nacs+nas)) {
            res += 'C';
            return 1;
        }
    }
    if (s[i] == '?' || (s[i] != 'N' && s[i] != 'A' && s[i] != 'C')) {
        if (solve(i+1, ns, nas, nacs)) {
            res += s[i] == '?' ? 'X' : s[i];
            return 1; 
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cerr.tie(0);
    cin >> n >> k >> s;
    if (solve(0, 0, 0, 0)) {
        reverse(all(res));
        assert(res.size() == n);
        cout << res << "\n";
    } else cout << "-1\n";
    return 0;
}
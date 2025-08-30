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

string s;
vi nums;
int n, m;

map<iii, int> memo;
int solve(int have, int ind, int used) {
    // cout << have << " " << ind << " " << used << "\n";
    if (ind == m) return 1;
    if (ind > m) return 0;
    if (s[ind] == '0') return 0;
    if (memo.count({have, ind, used})) return memo[{have, ind, used}];

    forn (i, n)  {
        if (!(have & (1 << i))) continue;
        string num = to_string(nums[i]);
        if (s[ind] != num[0]) continue;
        if (num.size() > 1 && s[ind+1] != num[1]) continue;
        have -= 1 << i;
        if (solve(have, ind + num.size(), used)) return 1;
        have += 1 << i;
    }
    return memo[{have, ind, used}] = !used && (solve(have, ind + 1, 1) || solve(have, ind + 2, 1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    m = s.size();
    cin >> n;
    forn (i, n) {
        int a; cin >> a;
        nums.pb(a);
    }

    cout << solve((1 << n) - 1, 0, 0) << "\n";
    return 0;
}
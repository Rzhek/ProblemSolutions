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
const int MOD = 1e8;
const long double EPS = 1e-9;

int n1, n2, k1, k2;

vector<vector<vvi>> memo;

ll solve(int a, int b, int aBefore, int bBefore) {
    if (a + b == n1 + n2) return 1;
    if (memo[a][b][aBefore][bBefore] != -1) return memo[a][b][aBefore][bBefore];
    ll res = 0;
    if (a < n1 && aBefore < k1) res += solve(a+1, b, aBefore+1, 0);
    res %= MOD;
    if (b < n2 && bBefore < k2) res += solve(a, b+1, 0, bBefore+1);
    res %= MOD;
    return memo[a][b][aBefore][bBefore] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n1 >> n2 >> k1 >> k2;
    memo = vector<vector<vvi>>(n1+1, vector<vvi>(n2+1, vvi(k1+1, vi(k2+1, -1))));
    cout << solve(0, 0, 0, 0) << "\n";
    
    return 0;
}
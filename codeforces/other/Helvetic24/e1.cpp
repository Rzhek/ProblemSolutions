#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;

const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    vl shorts(m), longs(m), total(m);
    vvl dp(n + 1, vl(m, 0));
    dp[0][0] = 1;
    forn(i, m) cin >> shorts[i];
    forn(i, m) cin >> longs[i];
    forn(i, m) total[i] = shorts[i] + longs[i];

    rep (i, 1, n + 1) {
        rep(j, 0, m) {
            rep(k, 0, m) {
                dp[i][k] += ((total[j] * total[k] - longs[j] * longs[k]) % MOD) * dp[i-1][j] % MOD;
                dp[i][k] %= MOD;
            }
        }
    }

    cout << accumulate(dp.back().begin(), dp.back().end(), 0LL, [](auto a, auto b){ 
        return (a + b) % MOD; 
    }) % MOD << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
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

vvl multiply(const vvl &A, const vvl &B) {
    assert(A[0].size() == B.size());
    int m = A[0].size();
    int a = A.size(), b = B[0].size();
    vvl res(a, vl(b, 0));
    forn(r, a) {
        forn(c, b) {
            ll val = 0;
            forn(ind, m) {
                val += (ll)A[r][ind] * B[ind][c] % MOD;
                val %= MOD;
            }
            res[r][c] = val;
        }
    }
    return res;
}

vvl fastExpo(vvl &base, int e) {
    vvl res(base.size(), vl(base.size(), 0));
    for (int i = 0; i < base.size(); i++) res[i][i] = 1;

    while (e > 0) {
        if (e & 1) res = multiply(res, base);
        base = multiply(base, base);
        e >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    vi shorts(m), longs(m);
    forn(i, m) cin >> shorts[i];
    forn(i, m) cin >> longs[i];

    vvl B(m, vl(2, 0)), C(2, vl(m, 0));
    forn(i, m) {
        B[i][0] = shorts[i] + longs[i];
        B[i][1] = longs[i];

        C[0][i] = shorts[i] + longs[i];
        C[1][i] = -longs[i];
    }

    
    vvl CB = multiply(C, B);
    vvl res = multiply(fastExpo(CB, n - 1), C);
    ll ans = 0;

    for (int i = 0; i < m; i++) {
        ans += (B[i][0] * res[0][0]) % MOD;
        ans %= MOD;
        ans += (B[i][1] * res[1][0]) % MOD;
        ans %= MOD;
    }
    cout << (ans + MOD) % MOD << "\n";
    
    return 0;
}
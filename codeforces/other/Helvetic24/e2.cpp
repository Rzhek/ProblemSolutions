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

vvl multiply(vvl &a, vvl &b) {
    // assert(a.front().size() == b.size());
    int n = b.size();
    vvl res(n, vl(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

vvl fastExpo(vvl &matrix, int e) {
    if (e == 1) return matrix;
    vvl tmp = fastExpo(matrix, e / 2);
    vvl res = multiply(tmp, tmp);
    if (e & 1) res = multiply(res, matrix);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    vl shorts(m), longs(m), total(m);
    forn(i, m) cin >> shorts[i];
    forn(i, m) cin >> longs[i];
    forn(i, m) total[i] = shorts[i] + longs[i];

    vl combs(m, 0);
    combs[0] = 1;
    vvl matrix(m, vl(m));
    forn(i, m) {
        forn(j, m) {
            matrix[i][j] = (total[i] * total[j] - longs[i] * longs[j]) % MOD;
        }
    }

    vvl res = fastExpo(matrix, n);
    cout << accumulate(all(res.front()), 0LL, [](auto a, auto b) {
        return (a + b) % MOD;
    }) << "\n";
    return 0;
}
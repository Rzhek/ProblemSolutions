#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
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

vvl multiply(const vvl &A, const vvl &B, int mod = INT_MAX) {
    assert(A[0].size() == B.size());
    int m = A[0].size();
    int a = A.size(), b = B[0].size();
    vvl res(a, vl(b, 0));
    forn(r, a) {
        forn(c, b) {
            ll val = 0;
            forn(ind, m) {
                val += (ll)A[r][ind] * B[ind][c] % mod;
                val %= mod;
            }
            res[r][c] = val;
        }
    }
    return res;
}

vvl fastExpo(vvl &mat, ll p, int mod = INT_MAX) {
    if (p == 1) return mat;
    vvl res = fastExpo(mat, p/2, mod);
    res = multiply(res, res, mod);
    if (p%2 == 1) res = multiply(res, mat, mod);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vvl mat = {
        {0, 3},
        {1, 2}
    };
    mat = fastExpo(mat, n, MOD);
    cout << mat[0][0] << "\n";
    return 0;
}
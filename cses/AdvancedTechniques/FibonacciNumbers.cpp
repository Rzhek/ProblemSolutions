#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const int MOD = 1e9+7;

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

vvl fastExpo(vvl &mat, ll p) {
    if (p == 0) { // Identity matrix case
        int n = mat.size();
        vvl identity(n, vl(n, 0));
        forn(i, n) identity[i][i] = 1;
        return identity;
    }
    if (p == 1) return mat;
    vvl res = fastExpo(mat, p/2);
    res = multiply(res, res);
    if (p%2 == 1) res = multiply(res, mat);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vvl mat = {
        {1, 1},
        {1, 0}
    }, first = {
        {1},
        {0}
    };
    ll x; cin >> x;

    mat = fastExpo(mat, x);
    mat = multiply(mat, first);

    cout << mat[1][0] << "\n";
}
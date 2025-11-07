#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

vvl multiply(const vvl &A, const vvl &B, const ll mod) {
    assert(A[0].size() == B.size());
    int m = A[0].size(), a = A.size(), b = B[0].size();
    vvl res(a, vl(b));
    for (int r = 0; r < a; r++) {
        for (int c = 0; c < b; c++) {
            for (int ind = 0; ind < m; ind++) {
                res[r][c] += A[r][ind] * B[ind][c] % mod;
                res[r][c] %= mod;
            }
        }
    }
    return res;
}

vvl fastExpo(vvl &mat, ll p, const ll mod) {
    if (p == 0) {
        int n = mat.size();
        vvl identity(n, vl(n));
        for (int i = 0; i < n; i++) identity[i][i] = 1;
        return identity;
    }
    if (p == 1) return mat;
    vvl res = fastExpo(mat, p / 2, mod);
    res = multiply(res, res, mod);
    if (p % 2) res = multiply(res, mat, mod);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, m; cin >> n >> m;
    while (n != 0 && m != 0) {
        vvl mat = {
            {0, 1},
            {1, 1}
        };
        vvl vert = {
            {1},
            {1}
        };

        mat = fastExpo(mat, n-1, m);
        vert = multiply(mat, vert, m);
        cout << (vert[0][0] + vert[1][0]) % m << "\n";
        cin >> n >> m;
    }

}
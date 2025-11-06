#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const int MOD = 1e9+7;

vvl multiply(const vvl &A, const vvl &B) {
    assert(A[0].size() == B.size());
    int m = A[0].size();
    int a = A.size(), b = B[0].size();
    vvl res(a, vl(b, 0));
    for (int r = 0; r < a; r++) {
        for (int c = 0; c < b; c++) {
            for (int ind = 0; ind < m; ind++) {
                res[r][c] += A[r][ind] * B[ind][c] % MOD;
                res[r][c] %= MOD;
            }
        }
    }
    return res;
}

vvl fastExpo(vvl &mat, ll p) {
    if (p == 0) { // Identity matrix case
        int n = mat.size();
        vvl identity(n, vl(n, 0));
        for(int i = 0; i < n; i++) identity[i][i] = 1;
        return identity;
    }
    vvl res = fastExpo(mat, p / 2);
    res = multiply(res, res);
    if (p % 2) res = multiply(res, mat);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    int m = s.size();

    vector<int> p(m);
    for (int i = 1; i < m; i++) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }

    vvl mat(m + 1, vl(m + 1));
    for (int u = 0; u < m - 1; u++) {
        for (int ch = 0; ch < 26; ch++) {
            int cur = u;
            while (cur >= -1 && cur + 1 < m && s[cur + 1] - 'A' != ch) {
                if (cur == -1) cur--;
                else cur = p[cur] - 1;
            }
            mat[u+1][cur+2]++;
        }
    }
    mat[0][0] = 25;
    mat[0][1] = 1;
    fill(mat.back().begin(), mat.back().end(), 0);
    mat[m][m] = 26;

    mat = fastExpo(mat, n);
    cout << mat[0].back() << "\n";
    
}

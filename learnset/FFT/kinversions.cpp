#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

using vi = vector<int>;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] =
            i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) 
        for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
            // C z = rt[j + k] * a[i+j+k];
            auto x = (double*)&rt[j + k],
                y = (double*)&a[i + j + k];
            C z(x[0] * y[0] - x[1] * y[1],
                x[0] * y[1] + x[1] * y[0]);
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i, 0, sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i, 0, sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    vd b(n); // [-n, -1] -> [1, n] -> -(idx+1)+n
    vd a(n); // [1, n] -> idx+1
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') b[i]++;
        else a[i]++; 
    }
    reverse(b.begin(), b.end());


    vd res = conv(b, a);

    for (int i = res.size() - (n - 1); i < res.size(); i++) {
        // cout << (abs(res[i]) < -1e5 ? 0 : (int)(res[i]+1e-5)) << "\n";
        cout << (int)(abs(res[i])+1e-5) << "\n";
    }
}
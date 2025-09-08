#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)


using vi = vector<int>;

array<vi, 2> manacher(const string& s) {
    int n = sz(s);
    array<vi, 2> p = {vi(n + 1), vi(n)};
    rep(z, 0, 2) for (int i = 0, l = 0, r = 0; i < n; i++) {
        int t = r - i + !z;
        if (i < r) p[z][i] = min(t, p[z][l + t]);
        int L = i - p[z][i], R = i + p[z][i] - !z;
        while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
            p[z][i]++, L--, R++;
        if (R > r) l = L, r = R;
    }
    return p;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();

    auto res = manacher(s);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        if (res[0][i] == 0) continue;
        int lastIdx = i + res[0][i] - 1;
        int length = res[0][i] * 2;
        ans[lastIdx] = max(ans[lastIdx], length);
    }

    for (int i = 0; i < n; i++) {
        int lastIdx = i + res[1][i];
        int length = res[1][i] * 2 + 1;
        ans[lastIdx] = max(ans[lastIdx], length);
    }

    for (int i = n - 1; i > 1; i--) {
        ans[i-1] = max(ans[i-1], ans[i] - 2);
    }

    for (auto x : ans) cout << x << " "; cout << "\n";
}
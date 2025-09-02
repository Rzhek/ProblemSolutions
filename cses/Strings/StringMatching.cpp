#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)x.size()
using vi = vector<int>;


vi pi(const string& s) {
    vi p(sz(s));
    rep(i, 1, sz(s)) {
        int g = p[i - 1];
        while (g && s[i] != s[g]) g = p[g - 1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}
vi match(const string& s, const string& pat) {
    vi p = pi(pat + '\0' + s), res;
    rep(i, sz(pat) + 1, sz(p)) if (p[i] == sz(pat))
        res.push_back(i - 2 * sz(pat));
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    string a, b; cin >> a >> b;
    cout << match(a, b).size() << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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

vi pi(const string &s) {
    vi p(sz(s));
    rep(i, 1, sz(s)) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g - 1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string str; cin >> str;
    int n = str.size();
    vi p = pi(str);
    // printArr(p);
    int res = 0, cur = p[n - 1];
    while (!res && cur > 0) {
        rep (i, 0, n - 1) {
            if (p[i] == cur) res = cur;
        }
        cur = p[cur-1];
    }

    // cout << res << "\n";
    if (res) {
        cout << str.substr(0, res) << "\n";
    } else {
        cout << "Just a legend\n";
    }

    return 0;
}
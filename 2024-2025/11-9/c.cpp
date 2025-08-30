#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const int mod2inv = 500000004;
const long double EPS = 1e-9;

bool isVar(string &s) {
    if (s.size() > 1) return false;
    if ('a' <= s[0] && s[0] <= 'z') return true;
    if ('A' <= s[0] && s[0] <= 'Z') return true;
    return false;
}

int mapping[128];
string build(vector<string>::iterator a, vector<string>::iterator b) {
    int last = 0;
    string res;
    memset(mapping, -1, sizeof(mapping));
    while (a != b) {
        if (isVar(*a)) {
            if (mapping[(*a)[0]] == -1) mapping[(*a)[0]] = last++;
            res += "*" + to_string(mapping[(*a)[0]]);
        } else {
            res += *a;
        }
        res += " ";
        a++;
    }
    res.pop_back();
    return res;
}

bool solve(vector<string> &suffixArray, string &s) {
    // int lo = 0, hi = suffixArray.size() - 1;
    // while (lo < hi) {
    //     int m = (lo + hi) / 2;
    //     // cout << lo << " " << m << " " << hi << "\n";
    //     int res = suffixArray[m].substr(0, s.size()).compare(s);
    //     if (res == 0) return true;
    //     if (res < 0) {
    //         // current word is less than or equal to the target
    //         lo = m + 1;
    //         // cout << "LESS\n";
    //     }  else {
    //         // current world is greater than the target
    //         // cout << "MORE\n";
    //         hi = m - 1;
    //     }
    // }
    auto it = lower_bound(all(suffixArray), s);
    return it != suffixArray.end() && it->substr(0, s.size()) == s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> tokens(n), suffixArray(n);
    forn (i, n) cin >> tokens[i];

    forn (i, n) {
        suffixArray[i] = build(tokens.begin() + i, tokens.end());
    }

    sort(all(suffixArray));

    // forn (i, n) {
    //     cout << i << ": " << suffixArray[i] << "\n";
    // }

    int q; cin >> q;
    while (q--) {
        int n, last = 0; cin >> n;
        memset(mapping, -1, sizeof(mapping));
        string s;

        while (n--) {
            string tmp; cin >> tmp;
            if (isVar(tmp)) {
                if (mapping[tmp[0]] == -1) mapping[tmp[0]] = last++;
                s += "*" + to_string(mapping[tmp[0]]);
            } else {
                s += tmp;
            }
            s += " ";
        }
        s.pop_back();

        // cout << "query " << s << "\n";
        if (solve(suffixArray, s)) cout << "yes\n";
        else cout << "no\n";
    }
}
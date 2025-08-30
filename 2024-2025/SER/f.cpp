#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
#define f first
#define s second

template<class T>
ostream & operator << (ostream & os, vector<T> v) {
   for (auto x : v) os << x << ' '; cout << "\n";
   return os;
}
template<class T, class U>
ostream &operator << (ostream & os, pair<T, U> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

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

struct SuffixArray {
    vi sa, lcp, rank;
    SuffixArray(string& s, int lim = 256) { // basic string<int>
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s) + 1), y(n), ws(max(n, lim));
        sa = lcp = rank = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i, 0, n) ws[x[i]]++;
            rep(i, 1, lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i, 1, n)
                a = sa[i - 1],
                b = sa[i],
                x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i, 0, n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
        for (k &&k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
    }
};



int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi seq(n);
    forn (i, n) cin >> seq[i];
    // for (int i = n; i < 2 * n; i++) seq[i] = seq[i - n];

    string s;
    // cout << seq;
    for (int i = 0; i < 2 * n; i++) {
        if (seq[i%n] > seq[(i + 1) % n]) s += '>';
        else s += '<';
        // cout << "compare: " << seq[i%n] << " & " << seq[(i+1)%n] << " " << s << "\n";
    }

    SuffixArray sa(s);
    // cout << s << "\n";

    vi idx(2 * n + 5);
    for (int i = 0; i < sa.sa.size(); i++) {
        // cout << i << ": " << sa.sa[i] << " " << s.substr(sa.sa[i]) << " | " << sa.lcp[i] << "\n";
        idx[sa.sa[i]] = i;
    }
    int M = sa.lcp.size(), N = sa.sa.size();
    for (int i = 0; i < n; i++) {
        int res = -1;
        if (idx[i] > 0 && sa.sa[idx[i]-1] != i + n) res = sa.lcp[idx[i]];
        else if (idx[i] > 0) res = sa.lcp[idx[i]-1];

        if (idx[i] + 1 < M) {
            res = max(res, sa.lcp[idx[i]+1]);
        }
        // assert(res != -1);
        if (res == -1) cout << "-1\n";
        else if (res >= n) cout << "-1\n";
        else cout << res + 1 << "\n";
    }



    




}
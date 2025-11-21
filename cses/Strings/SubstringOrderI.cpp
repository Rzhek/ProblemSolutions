#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) begin(x), end(x)

using vi = vector<int>;
using ll = long long;

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string& s, int lim=256) { // or basic string<int>
        int n = s.size() + 1, k = 0, a, b;
        vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i,1,n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
        s[i + k] == s[j + k]; k++);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    ll k; cin >> k;

    SuffixArray sa(s);

    
    for (int i = 1; i <= s.size(); i++) {
        // cout << i << ": " << sa.sa[i] << " " << sa.lcp[i] << ": " << s.substr(sa.sa[i]) << "\n";
        int len = s.size() - sa.sa[i] - sa.lcp[i];
        if (len < k) {
            k -= len;
            continue;
        }
        int start = sa.sa[i];
        int end = start + sa.lcp[i] + k - 1;
        // cout << start << " " << end << "\n";
        cout << s.substr(start, end - start + 1) << "\n";
        break;
    }
}
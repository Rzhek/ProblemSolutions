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

struct Trie {
    Trie *children[26];
    bool isWord;

    Trie() : isWord() { memset(children, 0, sizeof(children)); }
    
    void insert(string &s) {
        Trie *cur = this;
        forn (i, sz(s)) {
            if (!cur->children[s[i]-'a']) cur->children[s[i]-'a'] = new Trie();
            cur = cur->children[s[i]-'a'];
        }
        cur->isWord = true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    Trie *trie = new Trie();
    int n; cin >> n;
    while (n--) {
        string tmp; cin >> tmp;
        trie->insert(tmp);
    }

    n = sz(s);
    vector<ll> dp(n + 1);
    dp[0] = 1;

    for (int i = 0; i < n; i++) if (dp[i]) {
        Trie *cur = trie;
        for (int j = i; j < n; j++) {
            cur = cur->children[s[j]-'a'];
            if (!cur) break;
            if (cur->isWord) dp[j+1] += dp[i], dp[j+1] %= MOD;
        }
    }

    cout << dp[n] << "\n";
}
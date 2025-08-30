#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
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

const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

vvl memo;

ll solve(string &s, int n, int i, int skipped) {
    assert(i < n);
    // cout << i << " " << skipped << "\n";
    if (i == n - 1) {
        if (skipped) return s[i]-'0';
        return 1e9;
    }
    if (memo[i][skipped] != -1) return memo[i][skipped];
    
    ll res = inf;
    ll next = solve(s, n, i+1, skipped);
    if (next != 1e9) {
        res = min(res, (s[i] - '0') + next);
        res = min(res, (s[i] - '0') * next);
    }
    if (!skipped && i <= n - 3) {
        res = min(res, (s[i]-'0') * 10 + (s[i+1]-'0') + solve(s, n, i+2, 1));
        res = min(res, ((s[i]-'0') * 10 + (s[i+1]-'0')) * solve(s, n, i+2, 1));
    } else if (!skipped && i == n - 2) {
        // cout << "WTF: " << res << "\n";
        res = min(res, (ll)(s[i]-'0') * 10 + (s[i+1]-'0'));
        // cout << "WTF: " << res << "\n";
    }
    return memo[i][skipped] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        string s; cin >> s;
        if (n == 2) {
            cout << stoi(s) << "\n";
            continue;
        }
        memo = vvl(n, vl(2, -1));
        cout << solve(s, n, 0, 0) << "\n";
        // print2DArr(memo);
    }
    return 0;
}
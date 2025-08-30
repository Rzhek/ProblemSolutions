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

set<pair<char, int>> no_change, to_even, flip;
int dp[301][301][301][2], cur;
// true if it's possible to lead a secuence to odd result

int solve(int no_change, int to_even, int flip, int cur) {
    if (no_change + to_even + flip == 0) return cur;
    if (dp[no_change][to_even][flip][cur] != -1) return dp[no_change][to_even][flip][cur];
    dp[no_change][to_even][flip][cur] = 0;
    if (no_change) {
        dp[no_change][to_even][flip][cur] |= solve(no_change - 1, to_even, flip, cur);
    }
    if (to_even) {
        dp[no_change][to_even][flip][cur] |= solve(no_change, to_even - 1, flip, 0);
    }
    if (flip) {
        dp[no_change][to_even][flip][cur] |= solve(no_change, to_even, flip-1, cur ^ 1);
    }
    return dp[no_change][to_even][flip][cur];
}

void let_move() {
    char ch; cin >> ch;
    int x; cin >> x;
    if (ch == '+') {
        if (x % 2) flip.erase({ch, x});
        else no_change.erase({ch, x});
    } else {
        if (x % 2) no_change.erase({ch, x});
        else to_even.erase({ch, x});
    }
}

void move() {
    assert(dp[no_change.size()][to_even.size()][flip.size()]);
    if (no_change.size() && dp[no_change.size()-1][to_even.size()][flip.size()][cur]) {
        cout << no_change.begin()->first << " " << no_change.begin()->second << endl;
        no_change.erase(no_change.begin());
    } 
    else if (to_even.size() && dp[no_change.size()][to_even.size()-1][flip.size()][cur]) {
        cout << to_even.begin()->first << " " << to_even.begin()->second << endl;
        to_even.erase(to_even.begin());
        cur = 0;
    } 
    else if (flip.size() && dp[no_change.size()][to_even.size()][flip.size()-1][cur]) {
        cout << flip.begin()->first << " " << flip.begin()->second << endl;
        flip.erase(flip.begin());
        cur ^= 1;
    } 
    else {
        assert(false);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;

    forn(_, n) {
        char ch; cin >> ch;
        int x; cin >> x;
        if (ch == '+') {
            if (x % 2) flip.insert({ch, x});
            else no_change.insert({ch, x});
        } else {
            if (x % 2) no_change.insert({ch, x});
            else to_even.insert({ch, x});
        }
    }

    cin >> cur;
    cur %= 2;

    // cout << no_change.size() << to_even.size() << flip.size() << cur << "\n";

    if (solve(no_change.size(), to_even.size(), flip.size(), cur)) {
        cout << "me" << endl;
    } else {
        cout << "you" << endl;
        let_move();
    }

    while (no_change.size() || to_even.size() || flip.size()) {
        move();
        if (no_change.size() || to_even.size() || flip.size()) let_move();
    }

    // cout << solve(0, 0, 2, 0) << "\n";

}
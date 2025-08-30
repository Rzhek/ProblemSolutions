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

int solve(int n, int k, vector<iii> &data, vi bad) {
    auto [_, lastType, lastLen] = data.back();

    if (lastLen > k) return -1;
    if (bad.size() == 0) return n;
    if (bad.size() >= 3) return -1;

    if (bad.size() == 1) {
        auto [curStart, curType, curLen] = data[bad[0]];
        if (curStart + curLen == n) return -1;
        if (curLen == 2 * k && curType != lastType) return curStart + k;
        return -1;
    }
    // bad size == 2
    auto [s1, t1, l1] = data[bad[0]];
    auto [s2, t2, l2] = data[bad[1]];
    
    if (s2 + l2 != n) return -1;
    if (t1 != t2) return -1;
    if (l1 + l2 == k) return s1 + l1;
    if (l1 + l2 == 2 * k) return s1 + k - l2;
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<iii> data; // [startInd, 0/1, length]
        data.emplace_back(0, s[0]-'0', 0);
        forn (i, n) {
            auto &[pStart, pType, pLen] = data.back();
            if (s[i] - '0' == pType) pLen++;
            else {
                data.emplace_back(pStart + pLen, s[i] - '0', 1);
            }
        }

        vi badInds;
        for (int i = 0; i < data.size(); i++) {
            if (get<2>(data[i]) != k) badInds.pb(i);
        }
        cout << solve(n, k, data, badInds) << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

// int solve(string a, string b) {
//     int original[26]{}, cur[26]{};
//     int need = 0;
//     for (char ch : b) {
//         if (original[ch-'a']++ == 0) need++;
//     }

//     int l = 0;
//     ll res = 0;
//     for (int r = 0; r < a.size(); r++) {
//         if (++cur[a[r]-'a'] == original[a[r]-'a']) need--;
//         while (l < r && need == 0 && cur[a[l]-'a'] > original[a[l]-'a']) {
//             cur[a[l++]-'a']--;
//         }
//         if (need == 0) res += l + 1;
//     }
//     return res;
// }

int idk(int n, vector<int> nums) {
    int lo = 0, hi = 1e9;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // cout << solve("bcca", "abc") << "\n";
    // cout << solve("abcabc", "abc") << "\n";
    // cout << solve("abcabc", "aaabc") << "\n";
    cout << idk(4, {2, 1, 1}) << "\n";
    return 0;
}
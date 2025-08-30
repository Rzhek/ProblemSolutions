#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;;
        string s; cin >> s;
        vector<char> letters, digits;
        int l1 = 1e9, l2 = -1, d1 = 1e9, d2 = -1;

        forn (i, n) {
            if ('a' <= s[i] && s[i] <= 'z') {
                letters.pb(s[i]);
                l1 = min(l1, i);
                l2 = max(l2, i);
            }
            if ('0' <= s[i] && s[i] <= '9') {
                digits.pb(s[i]);
                d1 = min(d1, i);
                d2 = max(d2, i);
            }
        }

        if (letters.size() && digits.size()) {
            if (d2 < l1 && is_sorted(all(letters)) && is_sorted(all(digits))) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        else if (letters.size()) {
            if (is_sorted(all(letters))) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (is_sorted(all(digits))) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }


    }
    return 0;
}
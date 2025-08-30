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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vpi res;
        string s = to_string(n);
        int l = s.size();
        
        for (int len = 1; len <= 6; len++) {
            string str;
            for (int i = 0; i < len; i++) {
                str += s[i % l];
            }

            ll val = stoll(str);

            for (ll a = 1; a <= 10'000; a++) {
                ll b = n * a - val;
                if (1 <= b && b <= 10'000 && l * a - b == len) {
                    res.emplace_back(a, b);
                }
            }
        }
        cout << res.size() << "\n";
        for (auto [a, b] : res) {
            cout << a << " " << b << "\n";
        }
    }
    return 0;
}
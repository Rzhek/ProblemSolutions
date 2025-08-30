#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;

const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    ll res = max(1ll, n * (n - 1));
    for (ll a = n; a >= max(1ll, n - 2); a--) {
        for (ll b = a - 1; b >= max(1ll, a - 2); b--) {
            for (ll c = b - 1; c >= max(1ll, b - 2); c--) {
                res = max(res, (a * b * c) / __gcd(a, b) / __gcd(b, c) / __gcd(a, c));
            }
        }
    }

    cout << res << "\n";
    
    return 0;
}
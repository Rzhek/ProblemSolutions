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

vl getFactors(ll n) {
    vl factors;
    double ub = sqrt(n);
    for (ll i = 1; i <= ub; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) factors.push_back(n / i);
        } 
    }
    sort(all(factors));
    return factors;
}


int valid(ll x) {
    // while (x % 2 == 0) x /= 2;
    // while (x % 5 == 0) x /= 5;
    // return x == 1;
    cout << x << ": " << fmod(1e60, x) << "\n";
    return fmod(1e60, x) < 1e-3;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vl res;
    for (auto x : getFactors(n)) {
        if (valid(x)) res.pb(x);
    }
    cout << res.size() << "\n";
    for (auto x : res) {
        cout << x << "\n";
    }

    return 0;
}
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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

const int maxn = 2e5 + 10;
ll fact[maxn];

ll fastExpo(int a, int e) {
    if (e == 0) return 1ll;
    if (e == 1) return a;
    ll res = fastExpo(a, e / 2);
    res = res * res % MOD;
    if (e & 1) res = res * a % MOD;
    return res;
}

ll choose(int n, int r) {
    if (r > n) return 0;
    return fact[n] * fastExpo(fact[r], MOD-2) % MOD * fastExpo(fact[n-r], MOD-2) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= maxn; i++) fact[i] = fact[i-1] * i % MOD;
    tests {
        int n, k; cin >> n >> k;
        int num1 = 0, num0 = 0;
        forn(i, n) {
            char ch; cin >> ch;
            num1 += ch == '1';
            num0 += ch == '0';
        }
        ll res = 0;
        for (int i = k / 2 + 1; i <= k; i++) {
            res += choose(num1, i) * choose(num0, k - i);
            res %= MOD;
        }
        cout << res << "\n";
    }
    return 0;
}
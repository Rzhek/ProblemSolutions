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

const int maxn = 2e5+10;
map<int, vi> primes;

void getPrimes(int n) {
    double ub = sqrt(n);
    vi isPrime(n+1, 1);
    for (int i = 2; i <= ub; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            isPrime[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++) if (isPrime[i]) primes[i];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    getPrimes(maxn);

    int n; cin >> n;
    forn (i, n) {
        int x; cin >> x;
        for (auto &[p, arr] : primes) {
            // if (x == 1) break;
            int cnt = 0;
            while (x % p == 0) cnt++, x /= p;
            arr.pb(cnt);
            if (arr.size() > 2) arr.erase(max_element(all(arr)));
        }
    }

    int res = 1;
    for (auto &[p, arr] : primes) {
        sort(arr.begin(), arr.end());
        res *= pow(p, arr[1]);
    }
    cout << res << "\n";
    // bruh moment
    return 0;
}
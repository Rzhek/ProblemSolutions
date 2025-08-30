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

// * prime sieve
vi primes;
void getPrimes(int n) {
    vi isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    double ub = sqrt(n);
    for (int i = 2; i <= ub; i++) {
        if (isPrime[i] == 0) continue;
        for (int j = i + i; j <= n; j += i) {
            isPrime[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++) if (isPrime[i]) primes.pb(i); 
}

// * factors generation
vi getFactors(int n) {
    vi factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) factors.push_back(n / i);
        } 
    }
    sort(all(factors));
    return factors;
}

ll solve(int num, int i, vi &arr) {
    if (num == 1) {
        ll res = 1;
        forn (j, arr.size()) res *= pow(primes[j], arr[j]);
        return res;
    }
    ll res = inf;
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    getPrimes(1e5);
    int n;
    for (cin >> n; n != 0; cin >> n) {
        vi res;
        cout << solve(n * 2, 0, res);
    }
    return 0;
}
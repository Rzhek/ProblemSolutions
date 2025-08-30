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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    const int maxn = 7920;
    getPrimes(maxn);
    vvi res(maxn + 1, vi(1000, 0));
    for (int num = 1; num <= maxn; num++) {
        int cur = num;
        for (int i = 0; cur > 1 && i < primes.size(); i++) {
            while (cur % primes[i] == 0) {
                res[num][i]++;
                cur /= primes[i];
            }
        }
        if (cur != 1) cout << num << ": " << cur << "\n";
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 2; j <= maxn; j++) {
            res[j][i] += res[j-1][i];
        }
    } 
    tests {
        int n; cin >> n;
        int last = 0;
        forn (i, 1000) {
            if (res[n][i]) last = i;
        }
        forn (i, last+1) cout << res[n][i] << " ";
        cout << "\n";
    }
    return 0;
}
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

const int maxn = 1e5 + 10;
int n;
int color[maxn], visited[maxn];
vi edges[maxn];

void dfs(int u, int par) {
    visited[u] = 1;
    set<int> other;
    for (int v : edges[u]) {
        if (v > n) break;
        if (v == par) continue;
        if (!visited[v]) {
            dfs(v, u);
        }
        other.insert(color[v]);
    }
    int col = 1;
    for (auto x : other) {
        if (x == col) col++;
        else break;
    }
    color[u] = col;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    getPrimes(maxn);
    cout << primes.size() * maxn << "\n";
    for (int i = 1; i < maxn; i++) {
        for (int x : primes) {
            int j = i ^ x; 
            if (j < maxn && j > 0) {
                edges[i].pb(j);
                edges[j].pb(i);
            }
        }
        sort(all(edges[i]));
    }

    // tests {
    //     cin >> n;
    //     // for (int i = 1; i <= n; i++) color[i] = visited[i] = 0;
    //     // for (int i = 1; i <= n; i++) if (!visited[i]) dfs(1, 0);

    //     // cout << *max_element(color + 1, color + 1 + n) << "\n";
    //     // for (int i = 1; i <= n; i++) cout << color[i] << " ";
    //     // cout << "\n";
    // }
    return 0;
}
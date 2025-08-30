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

int n; 
vector<vector<vector<ld>>> dp;

ld solve(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return 0;
    if (x + y + z == 0) return 0;
    if (dp[x][y][z] > 0) return dp[x][y][z];
    return dp[x][y][z] = (n + x * solve(x-1, y, z) + y * solve(x+1, y-1, z) + z * solve(x, y+1, z-1)) / (x + y + z);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp = vector<vector<vector<ld>>>(n+1, vector<vector<ld>>(n+1, vector<ld>(n+1, 0)));

    vi freq(3, 0);
    forn (i, n) {
        int a; cin >> a;
        freq[a-1]++;
    }

    cout << fixed << setprecision(10) << solve(freq[0], freq[1], freq[2]) << "\n";

    return 0;
}
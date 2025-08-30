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
        vi nums(n);
        forn (i, n) cin >> nums[i];
        vvi vecA(n+1), vecB(n+1);
        vi last(n+1, -1), a(n+1), b(n+1), count(n+1, 0), res(n+1);
        ll ans = 0;

        forn (i, n) {
            a[i] = nums[i];
            b[i] = i + 1;
            int gcd = __gcd(a[i], b[i]);
            a[i] /= gcd;
            b[i] /= gcd;

            vecA[a[i]].pb(i);
            vecB[b[i]].pb(i);
        }

        rep (x, 1, n + 1) {
            for (int i : vecB[x]) {
                count[a[i]]++;
            }

            for (int y = x; y <= n; y += x) {
                for (int i : vecA[y]) {
                    int val = b[i];
                    if (last[val] != x) {
                        res[val] = 0;
                        for (int j = val; j <= n; j += val) {
                            res[val] += count[j];
                        }
                        last[val] = x;
                    }
                    ans += res[val];
                }
            }
            for (int i : vecB[x]) {
                count[a[i]]--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) ans--;
        }
        ans /= 2;
        cout << ans << "\n";

    }
    return 0;
}
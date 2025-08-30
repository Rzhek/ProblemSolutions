#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
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
        int n, m, k; cin >> n >> m >> k;
        vector<iii> nums(k);
        vi res(k);
        forn (i, k) {
            int r, c; cin >> r >> c;
            r--; c--;
            nums[i] = {i, r, c};
        }

        sort(all(nums), [](auto a, auto b) {
            if (get<2>(a) == get<2>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b);
        });
        
        int lastRow = -1, lastCol = 0;
        ll ans = 0;
        forn (j, k) {
            auto [i, r, c] = nums[j];
            // cout << i << " " << r << " " << c << "\n";
            if (r < lastRow) {
                continue;
            };
            ans += (r - lastRow) * (c - lastCol); 
            // cout << i << ": " << (r - lastRow) << " " << (c - lastCol) << "\n";
            lastRow = r;
            lastCol = c - 1;
        }

        ans += (n - 1 - lastRow) * m;

        cout << ans << "\n";






    }
    return 0;
}
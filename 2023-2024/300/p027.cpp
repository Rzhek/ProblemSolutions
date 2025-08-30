#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = __int128_t;
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
    vi values = {4, 6, 8, 12, 20};
    vi counts(5);
    forn(i, 5) cin >> counts[i];
    // vvl res(1, vl(501, 0));
    vector<vector<ld>> res(1, vector<ld>(501, 0));
    res[0][0] = 1;

    int last = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < counts[i]; j++) {
            last++;
            res.pb(vector<ld>(501, 0));
            for (int k = 0; k <= 500; k++) {
                if (!res[last-1][k]) continue;
                for (int a = 1; a <= values[i]; a++) {
                    res[last][k+a] += res[last-1][k];
                }
            }
            int sum = accumulate(all(res[last]), (ld)0);
            for (int i = 0; i <= 500; i++) {
                res[last][i] /= sum;
            }
        } 
    }
    vector<pair<ld, int>> nums;
    for (int i = 0; i <= 500; i++) {
        if (!res.back()[i]) continue;
        nums.emplace_back(res.back()[i], i);
    }

    sort(all(nums));
    reverse(all(nums));

    for (auto &[x, y] : nums) {
        // cout << x << ": " << y << "\n";
        cout << y << " ";
    }
    cout << "\n";

    return 0;
}
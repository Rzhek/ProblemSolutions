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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int N, K, Z; cin >> N >> K >> Z;
        vi nums(N, 0), sums(N, 0), max2(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
            sums[i] = i ? (sums[i-1] + nums[i]) : nums[i];
        }

        for (int i = 0; i < N - 1; i++) {
            max2[i] = max(max2[i-1], nums[i] + nums[i+1]);
        }
        max2[N-1] = max2[N-2];

        printArr(nums);
        printArr(sums);
        printArr(max2);

        int ans = 0;
        for (int z = 0; z <= Z; z++) {
            int len = K - 2 * z + 1;
            if (len < 0) break;
            // cout << len << "\n";
            ans = max(ans, sums[len] + z * max2[len]);
        }

        cout << ans << "\n";
    }
    return 0;
}
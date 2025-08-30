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
    int n, m; cin >> n >> m;
    vi nums(n+1, 0), ind(n+2, n+1), bad(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        nums[i] = a;
        ind[a] = i;
        bad[a] = ind[a-1] > i;
    }
    int cur = accumulate(all(bad), 0);

    while (m--) {
        int i1, i2; cin >> i1 >> i2;
        int a = nums[i1], b = nums[i2];
        swap(ind[a], ind[b]);
        swap(nums[i1], nums[i2]);

        // check affected nums only
        int delta = 0;
        vi check = {a, a + 1, b, b + 1};
        sort(all(check));
        check.erase(unique(check.begin(), check.end()), check.end());
        for (int num : check) {
            int isBad = ind[num] < ind[num-1];
            if (isBad == bad[num]) continue;
            if (isBad) delta++; else delta--;
            bad[num] = isBad;
        }
        cur += delta;
        cout << cur << "\n";

    }

    return 0;
}
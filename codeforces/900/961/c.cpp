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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vl nums(n+1, 1), op(n+1, 0);
        for (int i = 1; i <= n; i++) cin >> nums[i];
        
        int works = 1;
        for (int i = 1; i <= n; i++) {
            ll cur = nums[i], prev = nums[i-1];
            if (cur == 1 && prev != 1) {
                works = 0;
                break;
            }
            op[i] = op[i-1];
            while (prev != 1 && cur > prev) {
                op[i]--;
                prev *= prev;
            }
            while (cur < prev) {
                op[i]++;
                cur *= cur;
            }
            op[i] = max(0ll, op[i]);
        }

        if (!works) cout << "-1\n";
        else cout << accumulate(all(op), 0ll) << "\n";
    }
    return 0;
}
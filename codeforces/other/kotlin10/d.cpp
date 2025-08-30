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

using ll = long long;
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
        vl nums(n);
        forn(i, n) cin >> nums[i];
        ll res = 0;
        int len = 0;
        nums.pb(0);
        forn(i, n + 1) {
            if (nums[i] == 0) {
                if (len % 2 == 0) {
                    ll opt = 0;
                    for (int j = i - len; j < i; j += 2) {
                        opt += 2 * (nums[j] + nums[j+1]);
                    }
                    res += opt;
                } else {
                    ll opt1 = nums[i-len];
                    for (int j = i - len + 1; j < i; j += 2) {
                        opt1 += 2 * (nums[j] + nums[j+1]);
                    }
                    ll opt2 = nums[i-1];
                    for (int j = i - len; j < i - 1; j += 2) {
                        opt2 += 2 * (nums[j] + nums[j+1]);
                    }
                    res += min(opt1, opt2);
                }
                len = 0;
            } else {
                len++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
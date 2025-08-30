#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
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

const int MOD = 1e9+7;
const long double EPS = 1e-9;

int check(vi &nums, int k) {
    vi bits(20, 0);
    forn(i, k) {
        forn(bit, 20) {
            if (nums[i] & (1 << bit)) bits[bit]++;
        }
    }
    rep (i, k, nums.size()) {
        int oldVal = nums[i-k];
        int newVal = nums[i];
        forn(bit, 20) {
            int before = bits[bit] != 0;
            bits[bit] -= ((oldVal & (1 << bit)) != 0);
            bits[bit] += ((newVal & (1 << bit)) != 0);
            int after = bits[bit] != 0;
            if (before != after) return 0;
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vi nums(n);
        forn(i, n) cin >> nums[i];

        int lo = 1, hi = n;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (check(nums, m)) {
                hi = m - 1;
            } else {
                lo = m + 1;
            }
        }

        cout << (lo + hi) / 2 + 1 << "\n";


        
    }
    return 0;
}
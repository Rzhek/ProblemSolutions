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

int check(vi &nums, int removeInd) {
    if (removeInd < 0) return 0;
    int n = nums.size();
    if (removeInd == 0) {
        int prev = nums[1];
        int prevGcd = 1;
        for (int i = 2; i < n; i++) {
            int gcd = __gcd(nums[i], prev);
            if (gcd < prevGcd) return 0;
            prev = nums[i];
            prevGcd = gcd;
        }
        return 1;
    }
    int prev = nums[0];
    int prevGcd = 1;
    for (int i = 1; i < n; i++) {
        if (i == removeInd) continue;
        int gcd = __gcd(nums[i], prev);
        if (gcd < prevGcd) return 0;
        prev = nums[i];
        prevGcd = gcd;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vi nums(n);
        forn (i, n) cin >> nums[i];

        if (n <= 3) {
            cout << "YES\n";
            continue;
        }


        int prev = nums[0];
        int prevGcd = 1;
        int removed = 0;
        int works = 1;
        for (int i = 1; i < n && works; i++) {
            int gcd = __gcd(nums[i], prev);
            // cout << i << ": " << gcd << "\n";
            if (gcd < prevGcd) {
                works = check(nums, i - 2) || check(nums, i-1) || check(nums, i);
                // cout << check(nums, i - 2) << " " << check(nums, i-1) << " " << check(nums, i) << "\n";
                // cout << i << "\n";
                if (works) break;
            } else {
                prevGcd = gcd;
                prev = nums[i];
            }
        }

        // cout << check(nums, 2) << "\n";

        if (works) cout << "YES\n";
        else cout << "NO\n";


    }
    return 0;
}
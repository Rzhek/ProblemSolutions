#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
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

vector<long double> nums;
vector<vector<long double>> memo;

long double solve(int ind, ll streak) {
    if (ind == nums.size()) return streak * streak;
    long double fail, keep;
    if (memo[ind][0] != -1) {
        fail = memo[ind][0];
    }
    return nums[ind] * solve(ind + 1, streak + 1) + (1 - nums[ind]) * (streak * streak + solve(ind + 1, 0));
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    nums.resize(n);
    memo.resize(n, vector<long double>(2, -1));
    forn (i, n) cin >> nums[i];

    cout << fixed << setprecision(9) << solve(0, 0) << "\n";
    
    return 0;
}
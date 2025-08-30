#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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

vi nums;
vvi memo;

int solve(int ind, int pro) {
    if (ind >= nums.size()) return 0;
    if (memo[ind][pro] < 1e9) return memo[ind][pro];
    if (pro) {
        return memo[ind][pro] = min(solve(ind + 1, 0), solve(ind + 2, 0));
    }
    if (ind < nums.size() - 1) {
        return memo[ind][pro] = nums[ind] + min(solve(ind + 1, 1), nums[ind+1] + solve(ind + 2, 1));
    }
    return memo[ind][pro] = nums[ind] + solve(ind + 1, 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        nums.resize(n);
        memo = vvi(n, vi(2, 1e9));
        // vi nums(n);
        forn(i, n) cin >> nums[i];
        cout << solve(0, 0) << "\n";

        // int pro = 0;
        // int res = 0;
        // int remain = 2;
        // int i = 0;
        // while (i < n) {

        // }
    }

    return 0;
}
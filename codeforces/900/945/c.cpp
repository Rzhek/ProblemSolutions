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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vi nums(n), res(n);
        priority_queue<pii, vector<pii>, greater<pii>> maxi, mini;
        int start = 1;
        forn (i, n) {
            cin >> nums[i];
            if (nums[i] == 1) start = (i + 1);
        }


        rep (i, 1, n - 1) {
            if ((i & 1) == (start & 1)) {
                maxi.emplace(nums[i], i);
            } else {
                mini.emplace(nums[i], i);
            }
        }
        mini.emplace(nums[0], 0);
        mini.emplace(nums[n-1], n-1);

        int cur = n;
        while (maxi.size()) {
            auto [val, ind] = maxi.top();
            // cout << val << " ";
            maxi.pop();
            res[ind] = cur--;
        }
        while (mini.size()) {
            auto [val, ind] = mini.top();
            // cout << val << " ";
            mini.pop();
            res[ind] = cur--;
        }

        printArr(res);
    }
    
    return 0;
}
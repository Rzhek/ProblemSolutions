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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    n *= 2;
    vi nums(n);
    forn(i, n) cin >> nums[i];
    sort(all(nums));
    int res = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cur = 0, last = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (last) {
                    cur += abs(last - nums[k]);
                    last = 0;
                } else {
                    last = nums[k];
                }
            }
            res = min(res, cur);
        }
    }
    cout << res << "\n";

    return 0;
}
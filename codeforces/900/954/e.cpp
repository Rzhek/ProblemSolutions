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

const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; ll k; cin >> n >> k;
        map<int, vi> count;
        forn (i, n) {
            int x; cin >> x;
            count[x%k].pb(x);
        }

        vi odd;
        for (auto &[x, y] : count) {
            sort(all(y));
            if (y.size() & 1) odd.pb(x);
        }

        if (odd.size() > 1) {
            cout << "-1\n";
            continue;
        }

        ll res = 0;
        for (auto &[x, y] : count) {
            if (odd.size() && x == odd[0]) continue;
            // cout << x << ": \n";
            for (int i = 0; i < y.size(); i += 2) {
                // cout << y[i] << " " << y[i+1] << '\n';
                res += (y[i+1] - y[i]) / k; 
            }
        }

        if (odd.size()) {
            int ind = odd[0];
            int len = count[ind].size();
            vl leftSums(len+2, -1); leftSums[0] = 0;
            vl rightSums(len+2, -1); rightSums[len+1] = 0;
            for (int i = 1; i < len; i += 2) {
                leftSums[i+1] = leftSums[i-1] + (count[ind][i] - count[ind][i-1]) / k;
            }
            for (int i = len - 2; i >= 1; i -= 2) {
                // cout << i << "\n";
                rightSums[i+1] = rightSums[i+3] + (count[ind][i+1] - count[ind][i]) / k;
            }
            ll mini = min(leftSums[len-1], rightSums[2]);
            for (int i = 0; i < len; i += 2) {
                mini = min(mini, leftSums[i] + rightSums[i+2]);
            }
            for (int i = 1; i < len; i += 2) {
                mini = min(mini, leftSums[i-1] + (i+3 < len+2 ? rightSums[i+3] : 0) + (count[ind][i+1] - count[ind][i-1]) / k);
            }
            res += mini;
        }

        cout << res << "\n";
    }
    return 0;
}
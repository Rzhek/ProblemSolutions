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

const int inf = 1e9;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, pay; cin >> n >> pay;
        map<ll, ll> data;
        data[0] = 0;
        forn (i, n) {
            ll cost, val; cin >> cost >> val;
            vpl newData;
            for (auto &[curVal, maxAmt] : data) {
                if (cost <= maxAmt) {
                    if (data.count(curVal + val) && data[curVal + val] >= maxAmt - cost) continue;
                    newData.emplace_back(curVal + val, maxAmt - cost);
                }
            }
            for (auto &[x, y] : newData) data[x] = y;
            for (auto &[x, y] : data) y += pay;
        }
        ll res = 0;
        for (auto &[x, y] : data) res = max(res, x);
        cout << res << "\n";
    }
    
    return 0;
}
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
    int cases; cin >> cases;
    for (int t = 1; t <= cases; t++) {
        int n, k; cin >> n >> k;
        vi amt(k), cap(k), nums(n);
        vector<double> price(k);
        forn (i, k) cin >> amt[i] >> price[i] >> cap[i];
        
        forn (i, n) cin >> nums[i];
        int maxCap = *max_element(nums.begin(), nums.end());

        int bestInd = -1;
        double bestPrice = 1e9;
        forn (i, k) {
            if (cap[i] < maxCap) continue;
            int l = 0, r = 0;
            int cur = 0;
            int cnt = 0;
            while (l < n) {
                while (r < n && cur + nums[r] <= cap[i]) {
                    cur += nums[r++];
                }
                cnt++;
                l = r;
                cur = 0;
            }
            double curPrice = (cnt / amt[i] + (cnt % amt[i] != 0)) * price[i];
            if (curPrice < bestPrice) {
                bestInd = i;
                bestPrice = curPrice;
            }
        }
        cout << fixed << setprecision(2);
        cout << "Diaper Scenario #" << t << ": Buying box " << bestInd + 1 << ", you spend $" << bestPrice <<  "." << "\n";
    }

    return 0;
}
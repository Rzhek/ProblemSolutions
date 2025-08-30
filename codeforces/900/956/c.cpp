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
        int n; cin >> n;
        vvl nums(3, vl(n));
        ll tot = 0;
        forn (i, n) cin >> nums[0][i], tot += nums[0][i];
        forn (i, n) cin >> nums[1][i];
        forn (i, n) cin >> nums[2][i];

        tot = tot / 3 + (tot % 3 != 0);

        vi order = {0, 1, 2};
        int works = 0;
        int res[3][2];
        do {
            ll curVal = 0; 
            int curInd = 0;
            for (int i = 0; i < n; i++) {
                if (curVal == 0) res[order[curInd]][0] = i;
                curVal += nums[order[curInd]][i];
                if (curVal >= tot) {
                    res[order[curInd++]][1] = i;
                    curVal = 0;
                    if (curInd == 3) {
                        // res[order[curInd-1]][1] = n - 1;
                        break;
                    }
                }
            }
            works = (curInd == 3);
        } while (!works && next_permutation(all(order)));
        if (!works) cout << "-1\n";
        else {
            forn (i, 3) {
                forn (j, 2) {
                    cout << res[i][j] + 1 << " ";
                }
            }
            cout << "\n";
        }
    }

    

    return 0;
}
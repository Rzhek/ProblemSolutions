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

const int inf = 1e9;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

// void bruh() {
//     int n; cin >> n;
//         vi count(n+1);
//         forn (i, n) {
//             int a; cin >> a;
//             count[a]++;
//         }

//         int res = 0, bTurns = 0;
//         priority_queue<int> pq;

//         for (int i = 1; i <= n; i++) {
//             if (count[i] == 0) continue;
//             res++;

//             if (bTurns >= count[i]) {
//                 res--;
//                 bTurns -= count[i];
//                 pq.push(count[i]);
//             } else if (pq.size() && pq.top() > count[i]) {
//                 bTurns += pq.top() - count[i] + 1;
//                 pq.pop();
//                 pq.push(count[i]);
//             } else {
//                 bTurns++;
//             }

//         }
//         cout << res << "\n";
// }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        map<int, int> count;
        forn (i, n) {
            int a; cin >> a;
            count[a]++;
        }
        
        vi a;
        for (auto const &[k, v] : count) {
            a.pb(v);
        }

        n = a.size();
        vi dp(n+1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            vi ndp = dp;
            for (int k = 1; k <= n; k++) {
                int nv = dp[k-1] + a[i-1];
                if (nv <= i - k) {
                    ndp[k] = min(ndp[k], nv);
                }
            }
            dp = ndp;
        }
        int ans = n;
        while (dp[ans] >= inf) ans--;
        cout << n - ans << "\n";

    }
    return 0;
}
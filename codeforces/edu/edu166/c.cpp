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
        int n, m; cin >> n >> m;
        vpi data(n + m + 1);
        vi progs, testers;
        
        forn (i, n + m + 1) cin >> data[i].f;
        forn (i, n + m + 1) cin >> data[i].s;
        ll sum = 0;


        forn (i, n + m + 1) {
            auto [p, t] = data[i];

            if (progs.size() == n + 1) {
                testers.pb(i);
                sum += t;
                continue;
            }
            if (testers.size() == m + 1) {
                progs.pb(i);
                sum += p;
                continue;
            }
            if (p > t) {
                sum += p;
                progs.pb(i);
            } else {
                sum += t;
                testers.pb(i);
            }
        }

        vl ans(n + m + 1, sum);

        if (progs.size() == n + 1) {
            // if we have one extra programmer
            for (int p : progs) {
                // skipping a programmer wont result in inbalance
                ans[p] -= data[p].f;
            }
            for (int t : testers) {
                // skipping a tester will result in inbalance
                // so we need to convert the last programmer to tester
                ans[t] -= data[t].s;
                ans[t] -= data[progs.back()].f;
                ans[t] += data[progs.back()].s;
            }
        } else {
            // if we have one extra tester
            for (int t : testers) {
                // skipping a testers wont result in inbalance
                ans[t] -= data[t].s;
            }
            for (int p : progs) {
                // skipping a programmer will result in inbalance
                // so we need to convert the last tester to programmer
                ans[p] -= data[p].f;
                ans[p] -= data[testers.back()].s;
                ans[p] += data[testers.back()].f;
            }
        }

        printArr(ans);
    }
    return 0;
}
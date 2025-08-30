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

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, s, m; cin >> n >> s >> m;
        vi start(n), end(n+1, 0);
        forn (i, n) cin >> start[i] >> end[i+1];
        int works = 0;
        for (int i = 0; i <= n; i++) {
            int endtime = end[i];
            auto it = lower_bound(start.begin(), start.end(), endtime);
            if (it == start.end()) {
                if (m - endtime >= s) works = 1;
            } else {
                if (*it - endtime >= s) works = 1;
            }
        }

        if (works) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
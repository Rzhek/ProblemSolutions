#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
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
        int h, n; cin >> h >> n;
        vi a(n), c(n);
        forn (i, n) cin >> a[i];
        forn (i, n) cin >> c[i];

        priority_queue<pll, vpl, greater<pll>> pq;
        forn (i, n) {
            pq.emplace(0, i);
        }
        ll turn = 0;
        while (h > 0) {
            auto [time, ind] = pq.top();
            pq.pop();
            h -= a[ind];
            turn = max(turn, time);
            pq.emplace(time + c[ind], ind);
        }
        cout << turn + 1 << '\n';
    }
    return 0;
}
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

set<int> getFactors(int n) {
    set<int> factors;
    double ub = sqrt(n);
    for (int i = 1; i <= ub; i++) {
        if (n % i == 0) {
            factors.insert(i);
            if (i != n / i) factors.insert(n / i);
        } 
    }
    return factors;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, x; cin >> n >> x;
        int res = 1;
        set<int> factors = getFactors(x);
        set<int> cur;
        forn (i, n) {
            int a; cin >> a;
            if (!factors.count(a)) continue;
            vector<int> more {a};
            for (int num : cur) {
                if (factors.count(a * num)) more.pb(a * num);
            }
            for (int num : more) cur.insert(num);
            if (cur.count(x)) {
                res++;
                cur.clear();
                cur.insert(a);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
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
        vi a(n), b(n);
        forn (i, n) cin >> a[i];
        forn (i, n) cin >> b[i];

        int rate1 = 0, rate2 = 0;
        int pos = 0, neg = 0;
        forn (i, n) {
            if (a[i] > b[i]) rate1 += a[i];
            else if (a[i] < b[i]) rate2 += b[i];
            else if (a[i] == -1) neg++;
            else if (a[i] == 1) pos++;
            
        }

        // cout << rate1 << " " << rate2 << " " << free << "\n";

        while (pos > 0) {
            if (rate1 < rate2) rate1++;
            else rate2++;
            pos--;
        }
        while (neg > 0) {
            if (rate1 < rate2) rate2--;
            else rate1--;
            neg--;
        }
        cout << min(rate1, rate2) << "\n";
    }

    return 0;
}
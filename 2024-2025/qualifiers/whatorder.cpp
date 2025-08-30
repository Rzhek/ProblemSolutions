#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) { for (auto x : arr) cout << x << " "; cout << '\n'; }
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define printPair(pair) cout << "(" << pair.first << ", " << pair.second << ")"
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
    int n, c; cin >> n >> c;

    vi type(c), a(c), b(c);
    forn (i, c) {
        cin >> type[i];
        char x, y; cin >> x >> y;
        a[i] = x - 'A';
        b[i] = y - 'A';
    }

    vi order(n);
    forn (i, n) order[i] = i;

    int cnt = 0;
    do {
        vi ind(n);
        forn (i, n) ind[order[i]] = i;
        int works = 1;
        for (int i = 0; i < c && works; i++) {
            if (type[i] == 1) {
                works &= (ind[a[i]] < ind[b[i]]);
            } else if (type[i] == 2) {
                works &= (ind[a[i]] > ind[b[i]]);
            } else {
                works &= (abs(ind[a[i]] - ind[b[i]]) > 1);
            }
        }
        if (works) cnt++;
    } while (next_permutation(all(order)));

    cout << cnt << "\n";
    return 0;
}
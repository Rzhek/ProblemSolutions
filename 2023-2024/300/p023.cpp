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
    int n, x, y; cin >> n >> x >> y;
    vpi books(n);
    forn (i, n) {
        cin >> books[i].f >> books[i].s;
        if (books[i].f > x || books[i].s > y) {
            cout << "impossible";
            return 0;
        }
    }

    sort(all(books), [](pii &a, pii &b) {
        if (a.s == b.s) return a.f < b.f;
        return a.s < b.s;
    });
    reverse(all(books));

    int fitShelf = books[0].s < y;

    int h1 = books[0].s;
    int h2 = y - h1;

    int wLeft = x - books[0].f;
    int ind = 1;
    while (ind < n && books[ind].s > h2 && wLeft - books[ind].f >= 0) {
        wLeft -= books[ind].f;
        ind++;
    }

    if (ind == n) {
        if (fitShelf) cout << h1 << "\n";
        else cout << "-1\n";
        return 0;
    }

    if (books[ind].s > h2) {
        cout << "impossible\n";
        return 0;
    }

    vi remainWidth, reach(wLeft + 1, 0);
    for (int i = ind; i < n; i++) {
        remainWidth.pb(books[i].f);
    }
    int totalWidth = accumulate(all(remainWidth), 0);

    reach[0] = 1;
    int maxi = 0;
    for (int w : remainWidth) {
        for (int i = 0; i + w <= wLeft; i++) {
            if (reach[i]) reach[i+w] = 1, maxi = max(maxi, i+w);
        }
    }

    if (totalWidth - maxi <= x) {
        if (fitShelf) cout << h1 << "\n";
        else cout << "-1\n";
    } else {
        cout << "impossible";
    }

    return 0;
}
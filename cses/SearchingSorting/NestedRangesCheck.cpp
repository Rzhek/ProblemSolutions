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
    int n; cin >> n;
    vector<iii> ranges;
    vi ans1(n), ans2(n);
    forn (i, n) {
        int a, b; cin >> a >> b;
        ranges.emplace_back(a, b, i);
    }
    sort(all(ranges), [](auto a, auto b) {
        auto [l1, r1, i1] = a;
        auto [l2, r2, i2] = b;
        if (l1 != l2) return l1 < l2;
        return r1 > r2;
    });

    priority_queue<pii> pq; // [right_bound, ind]
    int last = 0;
    forn (i, n) {
        auto [l, r, ind] = ranges[i];
        ans2[ind] = last >= r;
        while (pq.size() && pq.top().f >= r) {
            ans1[pq.top().s] = 1;
            pq.pop();
        }


        pq.emplace(r, ind);
        last = max(last, r);
    }

    printArr(ans1);
    printArr(ans2);
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;

const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << "YES\n";
    int n; cin >> n;
    vpi nums(n);
    forn(i, n) cin >> nums[i].f, nums[i].s = i;

    sort(nums.rbegin(), nums.rend());
    vpi placement(n);
    vi replation(n);
    placement[nums[0].s] = {0, 0};
    
    // int dy = 1;
    // rep(i, 1, n) {
    //     auto [x_old, y_old] = placement[nums[i-1].s];
    //     int x_new = x_old + 1;
    //     int y_new;
    //     if (nums[i-1].f == 0) {
    //         y_new = y_old;
    //         relation[nums[i-1].s] =
    //     }
    // }

    // for (auto x : placement) {
    //     cout << x.f << " " << x.s << "\n";
    // }

    
    return 0;
}
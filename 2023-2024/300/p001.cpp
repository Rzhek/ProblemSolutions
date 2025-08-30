#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
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
using iii = tuple<int, int, int>;

const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

int k, n, r;
vector<char> res;

int solve(int ind, int last) {
    if (ind == n) return !--r;
    for (int i = last + k + 1; i < 26; i++) {
        res[ind] = i + 'a';
        if (solve(ind+1, i)) return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        cin >> k >> n >> r;
        res = vector<char>(n);
        solve(0, -k-1);
        for (int i = 0; i < n; i++) cout << res[i];
        cout << "\n";
    }

    return 0;
}
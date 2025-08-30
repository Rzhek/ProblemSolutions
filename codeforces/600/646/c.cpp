#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        int degree = 0;
        forn (i, n - 1) {
            int u, v; cin >> u >> v;
            degree += (u == x) || (v == x);
        }
        if (degree <= 1 || n % 2 == 0) {
            cout << "Ayush\n";
        } else {
            cout << "Ashish\n";
        }
    }

    return 0;
}
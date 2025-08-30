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

const int MOD = 1e9+7;
const long double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n, q; cin >> n >> q;
        vi sums(n + 1, 0);
        map<int, vi> ind;
        ind[0].pb(0);

        forn(i, n) {
            cin >> sums[i+1];
            sums[i+1] ^= sums[i];
            ind[sums[i+1]].pb(i+1);
        }

        // printArr(sums);
        // for (auto &[x, y] : ind) {
        //     cout << x << ": ";
        //     printArr(y);
        // }

        forn(i, q) {
            int l, r; cin >> l >> r;
            if (sums[r] == sums[l-1]) {
                cout << "YES\n";
                continue;
            }


            int lo = *--lower_bound(all(ind[sums[l-1]]), r);
            int hi = *lower_bound(all(ind[sums[r]]), l);
            if (lo > hi) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        cout << "\n";
    }



    
    
    return 0;
}
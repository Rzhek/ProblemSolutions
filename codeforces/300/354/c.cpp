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
    int n, k; cin >> n >> k;
    string seq; cin >> seq;
    int res = 0, removed;

    int l, r; // [l, r)
    for (l = 0, r = 0, removed = 0; l < n; l++) {
        while (r < n) {
            if (removed + (seq[r] == 'b') <= k) {
                removed += seq[r] == 'b';
                r++;
            } else break;
        }
        res = max(res, r - l);
        removed -= seq[l] == 'b';
    }
    for (l = 0, r = 0, removed = 0; l < n; l++) {
        while (r < n) {
            if (removed + (seq[r] == 'a') <= k) {
                removed += seq[r] == 'a';
                r++;
            } else break;
        }
        res = max(res, r - l);
        removed -= seq[l] == 'a';
    }

    cout << res << '\n';

    return 0;
}
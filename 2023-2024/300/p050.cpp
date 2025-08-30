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

vector<string> strs[21];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    forn (i, n) {
        string a; cin >> a;
        strs[a.size()].pb(a);
    }

    int res = 0;
    for (int size = 3; size <= 20; size++) {
        for (int start = 0; start < size - 1; start++) {
            map<string, int> patternCount;
            for (int i = 0; i < strs[size].size(); i++) {
                for (int j = i + 1; j < strs[size].size(); j++) {
                    string a = strs[size][i], b = strs[size][j];
                    if (a[start] == b[start] || a[start+1] == b[start+1]) continue;
                    if (a.substr(0, start) != b.substr(0, start) || a.substr(start + 2) != b.substr(start + 2)) continue;
                    a = a.substr(start, 2);
                    b = b.substr(start, 2);
                    if (a < b) swap(a, b);
                    string pattern = to_string(start) + a + b;
                    patternCount[pattern]++;
                }
            }
            for (auto &[k, v] : patternCount) if (v == 1) res++;
        }
    }
    cout << res << '\n';

    return 0;
}
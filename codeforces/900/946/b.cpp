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
        int n; cin >> n;
        string s; cin >> s;
        set<char> uniqie;
        vector<char> ways(26, 0);
        vector<char> sorted;
        for (char ch : s) {
            if (uniqie.count(ch)) continue;
            uniqie.insert(ch);
            sorted.pb(ch);
        }
        sort(all(sorted));
        for (int i = 0; i < sorted.size(); i++) {
            ways[sorted[i] - 'a'] = sorted[sorted.size() - i - 1];
        }
        // printArr(ways);
        for (int i = 0; i < s.size(); i++) {
            s[i] = ways[s[i] - 'a'];
        }
        cout << s << '\n';

    }
    
    return 0;
}
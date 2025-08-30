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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int x; cin >> x;
        vi nums;
        while (x) {
            nums.pb(x % 2);
            x /= 2;
        }
        for (int i = 0; i < nums.size();) {
            if (nums[i] == 0) {
                i++;
                continue;
            };
            int len = 1;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] == 0) break;
                len++;
            }
            if (len == 1) {
                i++;
                continue;
            };
            nums[i] = -nums[i];
            for (int j = 1; j <= len; j++) {
                nums[i+j] = 0;
            }
            if (i + len < nums.size()) nums[i+len] = 1;
            else nums.pb(1); 
            i = i + len;
        }
        cout << nums.size() << '\n';
        printArr(nums);

    }
    
    return 0;
}
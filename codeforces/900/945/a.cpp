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
    tests {
        vi nums(3);
        forn(i, 3) cin >> nums[i];
        sort(all(nums));
        int a = nums[0], b = nums[1], c = nums[2];
        int a1 = a / 2, b1 = b / 2, c1 = c / 2;
        int a2 = a % 2, b2 = b % 2, c2 = c % 2;

        if ((a + b + c) & 1) {
            cout << "-1\n";
            continue;
        }
        if (a + b <= c) {
            cout << a + b << "\n";
            continue;
        }
        cout << (a + b + c ) / 2 << "\n";

    }
    
    return 0;
}
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

vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.push_back(i);
            factors.push_back(n / i);
        } 
    }
    // sort(factors.begin(), factors.end());
    return factors;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vi nums(n);
        set<int> numset, res;
        forn(i, n) {
            cin >> nums[i];
            numset.insert(nums[i]);
        }

        sort(all(nums));
        int a = nums[0];
        vi nums2;
        int works = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % a) {
                nums2.pb(nums[i]);
            }
        }

        if (nums2.size() == 0) {
            cout << "Yes\n";
            continue;
        }

        a = nums2[0];
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] % a) {
                works = 0;
            }
        }

        cout << (works ? "Yes" : "No") << "\n";

    }
    return 0;
}
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
    int n; cin >> n;
    ll sum = 0;
    int maxi = 0;
    forn(i, n) {
        int a; cin >> a;
        sum += a;
        maxi = max(maxi, a); 
    }

    if (maxi > sum - maxi || sum % 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}
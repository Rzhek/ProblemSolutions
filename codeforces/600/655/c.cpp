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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        vi notInOrder;
        forn (i, n) {
            int a; cin >> a;
            if (a != i + 1) {
                notInOrder.push_back(i);
            }
        }
        if (sz(notInOrder) == 0) {
            cout << "0\n";
        } else if (notInOrder.back() - notInOrder[0] == sz(notInOrder) - 1) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }

    return 0;
}
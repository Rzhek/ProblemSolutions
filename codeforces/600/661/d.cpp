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
        int n; cin >> n;
        string seq; cin >> seq;
        vi zeros, ones, res(n);
        int ind = 0;
        forn (i, n) {
            if (seq[i] == '0') {
                if (ones.size()) {
                    res[i] = ones.back();
                    ones.pop_back();
                    zeros.push_back(res[i]);
                } else {
                    ind++;
                    res[i] = ind;
                    zeros.push_back(ind);
                }
            } else {
                if (zeros.size()) {
                    res[i] = zeros.back();
                    zeros.pop_back();
                    ones.push_back(res[i]);
                } else {
                    ind++;
                    res[i] = ind;
                    ones.push_back(ind);
                }
            }
        }
        cout << ind << "\n";
        printArr(res);
    }


    return 0;
}
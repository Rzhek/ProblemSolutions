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
        int N; cin >> N;
        vector<char> seq(N);
        int no = 0, so = 0, ea = 0, we = 0;
        forn(i, N) {
            cin >> seq[i];
            if (seq[i] == 'N') no++;
            else if (seq[i] == 'S') so++;
            else if (seq[i] == 'E') ea++;
            else if (seq[i] == 'W') we++;
        }
        int x = ea - we;
        int y = no - so;
        if (x % 2 || y % 2) {
            cout << "NO\n";
            continue;
        }
        if (x == 0 && y == 0) {
            if (no + ea < 2) {
                cout << "NO\n";
                continue;
            }
        }

        // cout << x << " " << y << "\n";
        x /= 2;
        y /= 2;
        vector<char> res(N);
        res[0] = 'R';
        if (seq[0] == 'N') {
            y--;
        } else if (seq[0] == 'S') {
            y++;
        } else if (seq[0] == 'E') {
            x--;
        } else {
            x++;
        }
        // cout << x << " " << y << "\n";
        rep(i, 1, N) {
            if (seq[i] == 'N' && y > 0) {
                y--;
                res[i] = 'R';
            } else if (seq[i] == 'S' && y < 0) {
                y++;
                res[i] = 'R';
            } else if (seq[i] == 'E' && x > 0) {
                x--;
                res[i] = 'R';
            } else if (seq[i] == 'W' && x < 0) {
                x++;
                res[i] = 'R';
            } else {
                res[i] = 'H';
            }
        }
        for (char ch : res) cout << ch;
        cout << "\n";
    }
    
    return 0;
}
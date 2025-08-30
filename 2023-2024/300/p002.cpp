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
const double PI = 3.141592653589793;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int c, r; cin >> c >> r;
        vi radii(c);
        int n = r * 2 + 2;
        vector<vector<double>> mat(n, vector<double>(n, 1e9));
        forn (i, c) cin >> radii[i];
        vpi points(n);
        forn (i, r) {
            int d, a; cin >> d >> a;
            d--;
            mat[2*i][2*i+1] = radii[d+1] - radii[d];
            mat[2*i+1][2*i] = radii[d+1] - radii[d];
            points[2*i] = {d, a};
            points[2*i+1] = {d+1, a};
        }
        int sc, sa, fc, fa;
        cin >> sc >> sa >> fc >> fa;
        sc--; fc--;
        points[2*r] = {sc, sa};
        points[2*r+1] = {fc, fa};

        forn(i, n) {
            forn(j, n) {
                if (i == j) {
                    mat[i][j] = 0;
                    continue;
                }
                if (points[i].f == points[j].f) {
                    mat[i][j] = mat[j][i] = min(abs(points[i].s - points[j].s), abs(360 - (points[i].s - points[j].s))) * radii[points[i].f] * PI / 180;
                }
            }
        }

        forn(k, n) forn(i, n) forn(j, n) mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

        cout << fixed << setprecision(2) << mat[n-2][n-1] << "\n";

        // forn(i, 10) {
        //     cout << mat[n-1]
        // }


        // for (auto [d, a] : points) {
        //     cout << d << " " << a << "\n";
        // }
        // print2DArr(mat);

    }
    return 0;
}
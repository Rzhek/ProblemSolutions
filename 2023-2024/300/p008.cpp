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

vi make, clean, check;
int res = 0;
// vector<map<int, int>> memo;

int checkInterval(int l, int r) {
    priority_queue<int> shoudlCleanDays;
    int cleanRem = 0;
    for (int i = r; i >= l; i--) {
        shoudlCleanDays.push(clean[i]);
        while (make[i] > cleanRem) {
            // make[i] -= cleanRem;
            // cout << i << " WTF\n";
            res++;
            if (shoudlCleanDays.empty()) break;
            cleanRem += shoudlCleanDays.top();
            shoudlCleanDays.pop();
        }
        if (make[i] > cleanRem) {
            // cout << i << " " << cleanRem << " -1\n";
            cout << "-1\n";
            return 0;
        }
        cleanRem -= make[i];
        // cout << i << " " << cleanRem << "\n";
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    make.resize(n, 0);
    clean.resize(n, 0);
    forn(i, n) cin >> make[i] >> clean[i];
    forn(i, d) {
        int a; cin >> a;
        check.pb(a-1);
    }

    int last = 0;
    for (int i : check) {
        // cout << last << " " << i << "\n";
        if (!checkInterval(last, i)) return 0;
        last = i + 1;
    }
    cout << res << '\n';

    
    



    
    // cout << "\n";
    // int res = 1e9;
    // for (auto &[x, y] : memo) {
    //     cout << x << " " << y << '\n';
    //     res = min(res, y);
    // } 
    // cout << res << '\n';


    return 0;
}


// for (int i = 1; i <= n; i++) {
    //     // cout << i << '\n';
    //     for (auto [mess, days] : memo[i-1]) {
    //         if (memo[i].count(mess+make[i])) memo[i][mess+make[i]] = min(memo[i][mess+make[i]], days);
    //         else memo[i][mess+make[i]] = days;
    //         int minClean = max(0, mess+make[i]-clean[i]);
    //         if (memo[i].count(minClean)) memo[i][minClean] = min(memo[i][minClean], days + 1);
    //         else memo[i][minClean] = days + 1;
    //     }
    //     if (check[i]) {
    //         if (!memo[i].count(0)) {
    //             cout << "-1\n";
    //             return 0;
    //         }
    //         int res = memo[i][0];
    //         memo[i].clear();
    //         memo[i][0] = res;
    //     }
    // }
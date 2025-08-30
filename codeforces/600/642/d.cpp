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

struct Compare {
    bool operator()(pii a, pii b){
        int len1 = a.s - a.f, len2 = b.s - b.f;
        return len1 == len2 ? a.s > b.s : len1 < len2;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    tests {
        int n; cin >> n;
        priority_queue<pii, vpi, Compare> pq;
        int ind = 1;
        vi res(n, 0);
        pq.emplace(0, n - 1);
        while (pq.size()) {
            auto [l, r] = pq.top();
            pq.pop();
            if (l > r) continue;
            if (l == r) {
                res[l] = ind++;
                continue;
            }
            int m = (l + r) / 2;
            // cout << m << "\n";
            res[m] = ind++;
            pq.emplace(l, m - 1);
            pq.emplace(m + 1, r);
        }
        // cout << ind << "\n";
        printArr(res);
    }

    return 0;
}
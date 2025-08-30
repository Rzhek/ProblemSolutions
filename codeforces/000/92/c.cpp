#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
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
        vector<int> counts(10, 0);
        string seq; cin >> seq;
        int n = seq.size();
        for (char digit : seq) counts[digit - '0']++;
        int res = *max_element(all(counts));

        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                int last = -1;
                int streak = 0;
                forn (k, n) {
                    if ((seq[k] - '0') == i && (seq[k] - '0') != last) {
                        last = (seq[k] - '0');
                        streak++;
                    } else if ((seq[k] - '0') == j && (seq[k] - '0') != last) {
                        last = (seq[k] - '0');
                        streak++;
                    }
                }
                // cout << i << " " << j << " " << streak << "\n";
                res = max(res, streak - (streak % 2));
            }
        }

        cout << n - res << '\n';

    }

    return 0;
}
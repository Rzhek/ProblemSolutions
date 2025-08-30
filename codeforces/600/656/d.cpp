#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n';
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

string str;

int solve(int l, int r, char ch) {
    if (r - l == 1) return str[l] != ch;
    int count1 = 0, count2 = 0;
    int m = (l + r) / 2;
    for (int i = l; i < m; i++) count1 += (str[i] == ch);
    for (int i = m; i < r; i++) count2 += (str[i] == ch);
    int len = r - l;
    return min(len / 2 - count1 + solve(m, r, ch + 1), len / 2 - count2 + solve(l, m, ch + 1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cin >> str;
        cout << solve(0, n, 'a') << '\n';
    }
    return 0;
}
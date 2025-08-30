#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define f first
#define s second
 
using ll = long long;
using pi = pair<ll, ll>;
using vii = vector<pi>;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vii data(n);
    rep(i, 0, n) cin >> data[i].f >> data[i].s;
    sort(data.begin(), data.end());
 
    ll res = 0;
    rep(i, 0, n) {
        auto [a, b] = data[i];
        res += b;
        res -= a * (n - i);
    }
 
    cout << res << '\n';
 
    return 0;
}
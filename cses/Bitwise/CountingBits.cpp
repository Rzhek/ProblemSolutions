#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> solveOne(ll N) {
    vector<ll> res(64);
    if (N == 0) return res; 
    int i = 60;
    while (!(N & (1ll << i))) i--;

    ll M = 0;
    for (; i >= 0; i--) {
        res[i] += M / 2;
        if (N & (1ll << i)) {
            M += 1ll << i;
            res[i] += N - M + 1;
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vector<ll> res = solveOne(n);
    cout << accumulate(res.begin(), res.end(), 0ll) << "\n";
}

/*
1000
N = 8
M = 8
res = [1, 4, 4, 4]
*/
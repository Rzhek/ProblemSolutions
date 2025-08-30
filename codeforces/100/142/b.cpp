#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> primes(1001 * 1001, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i <= 1001; i++) {
        if (primes[i] == 0) continue;
        int j = i;
        while (1) {
            j += i;
            if (j >= 1001 * 1001) break;
            primes[j] = 0;
        }
    }

    set<ll> tprimes;
    for (ll i = 0; i < primes.size(); i++) {
        if (primes[i] == 0) continue;
        tprimes.insert(i * i);
    }

    int n; cin >> n;
    while (n--) {
        ll num; cin >> num;
        if (tprimes.count(num)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fastExpo(ll a, int e) {
    if (e == 0) return 1;
    if (e % 2) return a * fastExpo(a, e-1);
    ll res = fastExpo(a, e/2);
    return res * res;
}

int solve() {
    ll k; cin >> k;
    int numDigits = 1;
    ll lb = 1, ub = 10;
    for (; k >= ub; numDigits++) {
        lb = ub;
        ub = lb + 9ll * (numDigits+1) * fastExpo(10, numDigits);
    }
    
    ll low = fastExpo(10, numDigits-1);
    ll high = fastExpo(10, numDigits);
    // cout << "!" << lb << " " << ub << "\n";
    while (low < high) {
        ll m = (low + high) / 2;
        
        ll lo = lb + (m - fastExpo(10, numDigits-1)) * numDigits;
        ll hi = lo + numDigits;

        // cout << m << " " << lo << " " << hi << "\n";

        if (lo <= k && k < hi) {
            return to_string(m)[k-lo] - '0';
        }
        if (k < lo) {
            high = m;
        } else {
            low = m + 1;
        }
    }
    // assert(false);
    return rand() % 10;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--) {
        cout << solve() << "\n";
    }
}
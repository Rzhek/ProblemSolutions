#include <bits/stdc++.h>
using namespace std;

vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.push_back(i);
            // factors.push_back(n / i);
        } 
    }
    // sort(factors.begin(), factors.end());
    return factors;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> factors = getFactors(n), res;
        int cur = n;
        for (int i = 0; i < factors.size(); i++) {
            if (factors[i] > cur) break;
            if (cur % factors[i]) continue;
            res.push_back(factors[i]);
            cur /= factors[i];
        }

        if (res.size() < 3) {
            cout << "NO\n";
        } else {
            int a = res[0], b = res[1];
            int c = n / a / b;
            cout << "YES\n";
            cout << a << " " << b << " " << c << '\n';
        }


    }
}
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
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

int getSum(ll num) {
    int res = 0;
    while (num) {
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll num; cin >> num;
        int s; cin >> s;
        int len = log10(num) + 1;

        int curSum = 0;
        ll target = 0;
        for (int i = len - 1; i >= 0; i--) {
            ll digit = num / (ll)pow(10, i) % 10;
            if (digit == 0) continue;
            target += digit * (ll)pow(10, i);
            curSum += digit;
            if (curSum > s) {
                while (curSum > s) {
                    // ll prevDigit = target / (ll)pow(10, i) % 10;
                    ll digit = target / (ll)pow(10, i) % 10;
                    target += (10 - digit) * (ll)pow(10, i);
                    curSum = getSum(target);
                    i++;
                }
                break;
            }
            // target += (10 - digit) * (int)pow(10, i);
        }

        cout << target - num << '\n';


    }

    return 0;
}
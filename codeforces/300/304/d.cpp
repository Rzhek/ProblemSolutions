#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll maxn = 5e6+1;
vector<int> isPrime(maxn, 1), divisor(maxn);
vector<ll> f(maxn);
 
void prefixSieve(){
    isPrime[1]= 0; 
    for(int i = 2; i < maxn; i++) if(isPrime[i]){
        divisor[i] = i;
        for(int j = i + i; j < maxn; j += i) {
            isPrime[j] = 0;
            divisor[j] = i;
        }
    }
    f[1] = 0;
    for(int i = 2; i < maxn; i++){
        f[i] = f[i / divisor[i]] + 1;
    }
    for(int i = 2; i < maxn; i++){
        f[i] += f[i - 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    prefixSieve();
    int t; cin >> t ;
    while (t--) {
        ll a, b; cin >> a >> b;
        // cout << f[a] - f[b] << '\n';
        ll res = 0;
        for (ll i = b + 1; i <= a; i++)
        {
            res += f[i];
        }
        cout << res << '\n';
    }
}

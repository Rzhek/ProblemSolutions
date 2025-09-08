#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const int maxn = 1e7+7;
int freq[maxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        
        int n; cin >> n;
        vi nums(n);
        for (auto &x : nums) cin >> x, freq[x]++;
        
        ll res = (ll)freq[0] * freq[1];

        for (int i = 2; i < maxn; i++) {
            if (!freq[i]) continue;
            res += (ll)(freq[0] + freq[1]) * freq[i];
            int k = 2;
            for (int j = i * k; j < maxn; j = i * ++k) {
                res += (ll)freq[i] * freq[j]; 
            }
        }

        cout << "Test case #" << tt << ": " << res << "\n\n";
        
        
        for (auto &x : nums) freq[x] = 0;
    }
}
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
const int MOD = 1e9+7;

const int maxn = 2e5+5; // or whatever the upper bound is
ll fen[maxn];
inline void add(int p, int val) { // make sure to convert to 1 base index
    // otherwise uncomment
    for (/*p++*/; p < maxn; p += p&-p) fen[p] += val, fen[p] %= MOD;
}
inline ll get(int p) { // inclusive [0, p]
    ll sum = 0;
    for (; p; p -= p&-p) sum += fen[p], sum %= MOD;
    return sum;
}
inline ll get(int a, int b) { // [a, b]
    return (get(b) - get(a - 1) + MOD) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi nums(n), compress;
    for (auto &x : nums) cin >> x;

    compress = nums;
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());

    for (auto &x : nums) {
        x = lower_bound(all(compress), x) - compress.begin() + 1;

        add(x, get(x - 1) + 1);
    }

    cout << get(n) << "\n";
}
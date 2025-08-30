#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, x, a, b, c; cin >> n >> k >> x >> a >> b >> c;
    deque<pii> mono;
    ll res = 0;
    
    for (int i = 0; i < n; i++) {
        if (!mono.empty() && mono.front().second <= i - k) mono.pop_front();
        while (!mono.empty() && mono.back().first >= x) mono.pop_back();
        mono.emplace_back(x, i);
        if (i >= k - 1) res ^= mono.front().first;
        x = ((ll)a * x + b) % c;
    }
    cout << res << "\n";
}
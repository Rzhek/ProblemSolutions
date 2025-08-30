#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
using L = array<int, 3>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, r; cin >> n >> m >> r;
    vector<P> candles(n);
    vector<L> lines(m);

    for (auto &[x, y] : candles) cin >> x >> y;
    for (auto &[a, b, c] : lines) cin >> a >> b >> c;

    vector<int> seen(1 << m);
    
    
}
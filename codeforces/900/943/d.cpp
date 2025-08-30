#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define forn(i, n) for (int i = 0; i < n; ++i)

vector<ll> moves, points, visited;
ll maxi;

ll solve(int pos, int remain) {
    if (remain == 0) return 0;
    if (visited[pos]) return points[pos] * remain;
    visited[pos] = 1;
    if (points[pos] == maxi) return points[pos] * remain;
    return max(points[pos] * remain, points[pos] + solve(moves[pos], remain - 1));
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k, pb, ps; cin >> n >> k >> pb >> ps;
        moves.resize(n);
        points.resize(n);
        forn(i, n) {
            cin >> moves[i];
            moves[i]--;
        };
        forn(i, n) cin >> points[i];
        maxi = *max_element(points.begin(), points.end());

        visited = vector<ll>(n, 0);
        ll b = solve(pb - 1, k);
        visited = vector<ll>(n, 0);
        ll s = solve(ps - 1, k);

        if (b > s) {
            cout << "Bodya\n";
        } else if (s > b) {
            cout << "Sasha\n";
        } else {
            cout << "Draw\n";
        }
    }
    return 0;
}
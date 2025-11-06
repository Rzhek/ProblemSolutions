#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

struct BIT {
    vi bit;

    BIT(int n): bit(n) {}

    int get(int i) { // [0, i]
        int res = 0;
        for (; i; i -= i&-i) res += bit[i];
        return res;
    }

    int get(int l, int r) { // [l, r]
        return get(r) - get(l - 1);
    }

    void add(int p, int v) {
        for (; p < bit.size(); p += p&-p) bit[p] += v;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    priority_queue<pii, vector<pii>, greater<pii>> pq1, pq2;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pq1.push({x, i});
        pq2.push({x, i});
    }

    vector<array<int, 5>> queries(q);
    vi res(q);
    for (int i = 0; i < q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        queries[i] = {i, a, b, c, d};
    }

    sort(queries.begin(), queries.end(), [&](auto &a, auto &b) {
        return a[3] < b[3];
    });


    BIT bit(n + 1);
    for (auto [i, a, b, c, d] : queries) {
        while (pq1.size() && pq1.top().first < c) {
            auto [x, ind] = pq1.top();
            pq1.pop();
            bit.add(ind, 1);
        }
        res[i] -= bit.get(a, b);
    }

    sort(queries.begin(), queries.end(), [&](auto &a, auto &b) {
        return a[4] < b[4];
    });


    bit = BIT(n + 1);
    for (auto [i, a, b, c, d] : queries) {
        while (pq2.size() && pq2.top().first <= d) {
            auto [x, ind] = pq2.top();
            pq2.pop();
            bit.add(ind, 1);
        }
        res[i] += bit.get(a, b);
    }

    for (int i = 0; i < q; i++) cout << res[i] << "\n";
}
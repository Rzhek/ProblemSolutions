#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

struct Node {
    Node *left, *right;
    int l, r, m;
    int l_x1, l_x2, r_x1, r_x2;
    int l_y1, l_y2, r_y1, r_y2;

    Node (vector<pii> &pts, int l, int r) : l(l), r(r), m((l+r)/2) {
        if (l + 1 == r) {
            
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    vector<pii> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;

    Node ST(pts, 0, n);

    while (q--) {
        int a, b; cin >> a >> b;
        cout << ST.query(a-1, b) << "\n";
    }


    return 0;
}
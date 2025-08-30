#include <bits/stdc++.h>
using namespace std;

typedef struct Node Node;
typedef long long ll;

struct Node {
    ll l, h, m, val;
    int prop;
    Node * left, * right;

    Node(int lo, int hi) {
        l = lo;
        h = hi;
        // cout << "creating node " << l << " " << h << endl;
        m = (l + h) / 2;
        val = prop = 0;
        left = right = nullptr;
    }

    ll value() {
        return prop ? h - l - val + 1 : val;
    }

    void createNodes() {
        left = new Node(l, m);
        right = new Node(m + 1, h);
    }

    void update(int lo, int hi) {
        // cout << "update node " << l << " " << h << " with " << lo << " " << hi << endl;
        // no over
        if (hi < l || h < lo) {
            // cout << "no over" << endl;
            return;
        }

        // total over
        if (lo <= l && h <= hi) {
            // cout << "total over" << endl;
            prop ^= 1;
            return;
        }

        // Partial over
        // cout << "partial over" << endl;
        if (!left) {
            createNodes();
        }
        left->prop ^= prop; 
        right->prop ^= prop;
        prop = 0;
        left->update(lo, hi);
        right->update(lo, hi);
        val = left->value() + right->value();
    }
};

int main() {
    ll res = 0, bound = pow(10, 9);
    int n; cin >> n;
    Node SegTree = Node(0, bound);
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> queries;

    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries.push({x1, y1, y2});
        queries.push({x2, y1, y2});
    }

    while (!queries.empty()) {
        ll next, cur;
        do {
            auto [x, y1, y2] = queries.top();
            queries.pop();
            cur = x;
            SegTree.update(y1, y2 - 1);
            if (!queries.empty()) {
                next = get<0>(queries.top());
            } else {
                next = -1;
            }
        } while (next == cur);
        if (next != -1) {
            res += SegTree.value() * (next - cur);
        }
    }
    cout << res << endl;
    return 0;
}
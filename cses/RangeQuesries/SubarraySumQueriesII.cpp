#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

struct Info {
    ll total, prefix, suffix, best;

    Info(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        total = a;
        prefix = b;
        suffix = c;
        best = d;
    }
};

struct Node {
    int l, r, m;
    Info info;
    Node *lo, *hi;

    Node(vi &nums, int l, int r): l(l), r(r), m((l+r)/2) {
        if (l + 1 == r) {
            lo = hi = nullptr;
            info = Info(
                nums[l],
                max(nums[l], 0),
                max(nums[l], 0),
                max(nums[l], 0)
            );
        } else {
            lo = new Node(nums, l, m);
            hi = new Node(nums, m, r);
            info = Info(
                lo->info.total + hi->info.total,
                max(lo->info.prefix, lo->info.total + hi->info.prefix),
                max(hi->info.suffix, hi->info.total + lo->info.suffix),
                max({lo->info.best, hi->info.best, lo->info.suffix + hi->info.prefix})
            );
        }
    }

    Info query(int a, int b) {
        if (a <= l && r <= b) {
            return info;
        }
        if (b <= l || r <= a) {
            return Info();
        }
        
        Info left = lo->query(a, b);
        Info right = hi->query(a, b);

        return Info(
            left.total + right.total,
            max(left.prefix, left.total + right.prefix),
            max(right.suffix, right.total + left.suffix),
            max({left.best, right.best, left.suffix + right.prefix})
        );
    }
};


int main() {
    int n, q; cin >> n >> q;
    vi nums(n);
    for (auto &x : nums) cin >> x;
    Node ST(nums, 0, n);
    while (q--) {
        int a, b; cin >> a >> b;
        cout << ST.query(a - 1, b).best << "\n"; 
    }
}
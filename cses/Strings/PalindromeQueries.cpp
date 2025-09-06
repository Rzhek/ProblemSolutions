#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll HASH = 313, MOD = 1e9+7, maxn = 2e5+5;
ll hashpower[maxn];

ll fastpow(ll val, int e) {
    if (e == 0) return 1;
    ll tmp = fastpow(val, e / 2);
    tmp = tmp * tmp;
    tmp %= MOD;
    if (e % 2) tmp = (tmp * val) % MOD;
    return tmp;
}

struct Node {
    int l, r, m, len;
    ll val;
    Node *lo, *hi;

    Node(int l, int r, string &s): l(l), r(r), m((l+r)/2), len(r-l) {
        if (l + 1 == r) {
            lo = hi = nullptr;
            val = s[l] - 'a' + 1;
        } else {
            lo = new Node(l, m, s);
            hi = new Node(m, r, s);
            val = (lo->val + (hashpower[lo->len] * hi->val % MOD)) % MOD;
        }
    }

    void update(int i, char ch) {
        if (l + 1 == r) {
            val = ch - 'a' + 1;
            return;
        }
        if (i < m) lo->update(i, ch);
        else hi->update(i, ch);
        val = (lo->val + (hashpower[lo->len] * hi->val % MOD)) % MOD;
    }

    ll query(int a, int b) { // [a, b)
        if (a == 0) return query(b);
        return (query(b) - query(a) + MOD) % MOD * fastpow(hashpower[a], MOD - 2) % MOD;
    }

    int query(int i) { // [0, i)
        if (i == r) return val;
        if (i <= m) return lo->query(i);
        return (lo->val + (hashpower[lo->len] * hi->query(i) % MOD)) % MOD; 
    }

};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    hashpower[0] = 1;
    for (int i = 1; i < maxn; i++) hashpower[i] = hashpower[i-1] * HASH % MOD;

    int n, q; cin >> n >> q;
    string s; cin >> s;

    Node ST_FW(0, n, s);
    reverse(s.begin(), s.end());
    Node ST_BW(0, n, s);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int i; cin >> i;
            char ch; cin >> ch;
            ST_FW.update(i-1, ch);
            ST_BW.update(n-i, ch); // n - (i-1) - 1
        } else {
            int a, b; cin >> a >> b;
            if (ST_FW.query(a-1, b) == ST_BW.query(n-b, n-a+1)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
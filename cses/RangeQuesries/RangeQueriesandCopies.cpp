#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

struct PST
{
    PST *l = 0, *r = 0;
    int lo, hi;
    ll val = 0, lzadd = 0;
    PST(vl &v, int lo, int hi) : lo(lo), hi(hi)
    {
        if (lo + 1 < hi)
        {
            int mid = lo + (hi - lo) / 2;
            l = new PST(v, lo, mid);
            r = new PST(v, mid, hi);
            val = l->val + r->val;
        }
        else
            val = v[lo];
    }
    ll query(int L, int R)
    {
        if (R <= lo || hi <= L)
            return 0; // idempotent
        if (L <= lo && hi <= R)
            return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    PST *add(int L, int R, ll v)
    {
        if (R <= lo || hi <= L)
            return this;
        PST *n;
        if (L <= lo && hi <= R)
        {
            n = new PST(*this);
            n->val += v;
            n->lzadd += v;
        }
        else
        {
            push();
            n = new PST(*this);
            n->l = l->add(L, R, v);
            n->r = r->add(L, R, v);
            n->val = n->l->val + n->r->val;
        }
        return n;
    }
    void push()
    {
        if (lzadd == 0)
            return;
        l = l->add(lo, hi, lzadd);
        r = r->add(lo, hi, lzadd);
        lzadd = 0;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<PST*> lst;
    lst.push_back(new PST(a, 0, n));

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int k, a, x; cin >> k >> a >> x;
            lst[k-1] = lst[k-1]->add(a-1, a, x - lst[k-1]->query(a-1, a));
        } else if (type == 2) {
            int k, a, b; cin >> k >> a >> b;
            cout << lst[k-1]->query(a-1, b) << "\n";
        } else {
            int k; cin >> k;
            lst.push_back(lst[k-1]);
        }
    }

    
}
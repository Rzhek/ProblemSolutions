#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using l2 = array<ll, 2>;
using l3 = array<ll, 3>;
const int inf = 1e9;
const ll lnf = 1e15;

struct cmp {
    bool operator()(const set<l3>::iterator& a, const set<l3>::iterator& b) const {
        return *a < *b;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<ld, set<set<l3>::iterator, cmp>> pq;
    set<l3> st;
    vector<l2> guys(n);

    ll torque = 0;
    ld res = 0;
    for (auto &[pos, w] : guys) cin >> pos >> w, torque -= pos * w;

    for (auto [pos, w] : guys) {
        pq[w].insert(st.insert({torque < 0 ? -pos : pos, w, 1}).first);
    }
    pq[-inf] = {st.insert({lnf, 0, 1}).first};
    torque = abs(torque);

    while (torque) {
        auto &[priority, ggs] = *pq.rbegin();
        auto cur = *ggs.begin();
        auto [p1, w1, cnt1] = *cur;
        ggs.erase(ggs.begin());
        st.erase(cur);
        
        if (ggs.size() == 0) pq.erase(priority);
        
        auto next = st.upper_bound({p1, 0, 0});
        auto [p2, w2, cnt2] = *next;
        if (p2 != lnf) {
            pq[(ld)w2 / cnt2].erase(next);
            if (pq[(ld)w2 / cnt2].size() == 0) pq.erase((ld)w2 / cnt2);
            st.erase(next);
        }
        
        ll can = p2 - p1;
        ld need = (ld)torque / w1;
        if (need < can) {
            res += need * cnt1;
            torque = 0;
        } else {
            res += can * cnt1;
            torque -= can * w1;
            pq[(ld)(w1 + w2) / (cnt1 + cnt2)].insert(st.insert({p2, w1 + w2, cnt1 + cnt2}).first);
        }
    }
    
    cout << fixed << setprecision(10) << res << "\n";
}
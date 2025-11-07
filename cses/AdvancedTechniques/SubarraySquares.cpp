#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line{
    ll k,m;
    ll eval(ll x) { return k * x + m; }
};
struct LineContainer{
    deque<Line> dq;
    bool bad(const Line &a, const Line &b, const Line &c){
        return (b.m - a.m) * (a.k - c.k) >= (c.m - a.m) * (a.k - b.k);
    }
    void add(ll k, ll m){
        Line l = {k,m};
        while (dq.size() >= 2 && bad(dq[dq.size()-2], dq.back(), l)) dq.pop_back();
        dq.push_back(l);
    }
    ll query(ll x){
        while (dq.size() >= 2 && dq[0].eval(x) >= dq[1].eval(x)) dq.pop_front();
        return dq[0].eval(x);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, K; cin >> n >> K;
    vector<LineContainer> LCs(K + 1);
    LCs[0].add(0, 0);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        cur += x;
        for (int k = min(K, i + 1); k > 0; k--) {
            LCs[k].add(-2 * cur, LCs[k-1].query(cur) + 2 * cur * cur);
        }
    }

    cout << LCs[K-1].query(cur) + cur * cur << "\n";    
}